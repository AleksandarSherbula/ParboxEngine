#include "pbxpch.h"
#include "Input.h"
#include "Log.h"
#include "Engine.h"

#include "GLFW/glfw3.h"

namespace pbx
{
	bool Input::oldKeyState[1024] = { false };
	bool Input::newKeyState[1024] = { false };
	InputState Input::keyboardState[1024] = { false };

	bool Input::oldMouseButtonsState[8] = { false };
	bool Input::newMouseButtonsState[8] = { false };
	InputState Input::mouseState[8] = { false };

	MouseCoordinates Input::mousePos = { 0, 0 };
	MouseCoordinates Input::mouseScroll = { 0, 0 };

	void Input::Scan()
	{
		for (int key = 0; key < 1024; key++)
		{
			keyboardState[key].isPressed = false;
			keyboardState[key].isReleased = false;

			if (newKeyState[key] != oldKeyState[key])
			{
				if (newKeyState[key])
				{
					keyboardState[key].isPressed = !keyboardState[key].isHeld;
					keyboardState[key].isHeld = true;
				}
				else
				{
					keyboardState[key].isReleased = true;
					keyboardState[key].isHeld = false;
				}
			}

			oldKeyState[key] = newKeyState[key];
		}

		for (int mb = 0; mb < 8; mb++)
		{
			mouseState[mb].isPressed = false;
			mouseState[mb].isReleased = false;

			if (newMouseButtonsState[mb] != oldMouseButtonsState[mb])
			{
				if (newMouseButtonsState[mb])
				{
					mouseState[mb].isPressed = !mouseState[mb].isHeld;
					mouseState[mb].isHeld = true;
				}
				else
				{
					mouseState[mb].isReleased = true;
					mouseState[mb].isHeld = false;
				}
			}

			oldMouseButtonsState[mb] = newMouseButtonsState[mb];
		}
	}

	bool GetKeyPressed(int k)
	{
		return Input::keyboardState[k].isPressed;
	}

	bool GetKeyHeld(int k)
	{
		return Input::keyboardState[k].isHeld;
	}

	bool GetKeyReleased(int k)
	{
		return Input::keyboardState[k].isReleased;
	}

	bool GetMouseButtonPressed(int mb)
	{
		return Input::mouseState[mb].isPressed;
	}

	bool GetMouseButtonHeld(int mb)
	{
		return Input::mouseState[mb].isHeld;
	}

	bool GetMouseButtonReleased(int mb)
	{
		return Input::mouseState[mb].isReleased;
	}

	int GetMouseX()
	{
		return Input::mousePos.x;
	}

	int GetMouseY()
	{
		return Input::mousePos.y;
	}

	int GetScrollX()
	{
		return Input::mouseScroll.x;
	}

	int GetScrollY()
	{
		return Input::mouseScroll.y;
	}

	void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
	{
		if (key >= 0 && key < 1024)
		{
			if (action == GLFW_PRESS)
				Input::newKeyState[key] = true;
			else if (action == GLFW_RELEASE)
				Input::newKeyState[key] = false;
		}
	}

	void MouseButtonCallback(GLFWwindow* window, int button, int action, int mode)
	{
		if (button >= 0 && button < 8)
		{
			if (action == GLFW_PRESS)
				Input::newMouseButtonsState[button] = true;
			else if (action == GLFW_RELEASE)
				Input::newMouseButtonsState[button] = false;
		}
	}

	void CursorPositionCallback(GLFWwindow* window, double PosX, double PosY)
	{
		glfwGetCursorPos(window, &PosX, &PosY);
		Input::mousePos.x = (int)PosX;
		Input::mousePos.y = (int)PosY;
	}

	void ScrollCallback(GLFWwindow* window, double OffsetX, double OffsetY)
	{
		Input::mouseScroll.x = (int)OffsetX;
		Input::mouseScroll.y = (int)OffsetY;
	}
}
