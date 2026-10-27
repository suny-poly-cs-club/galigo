#pragma once

//ONLY use these functions to check user inputs!

/**Fetch the current state of user inputs, updating the current internal state of the controls.
 * Checks the first connected controller if one is present, if not it will check they keyboard
 */
void updateInputState();

/**Check if the left stick was pressed upwards. Maps to W on keyboard.
 * @return true if the stick is pushed upwards
 */
bool controllerStickUp();
/**Check if the left stick was pressed downward. Maps to S on keyboard.
 * @return true if the stick is pushed downward.
 */
bool controllerStickDown();
/**Check if the left stick was pressed left. Maps to A on keyboard.
 * @return true if the stick is pushed left
 */
bool controllerStickLeft();
/**Check if the left stick was pressed right. Maps to D on keyboard.
 * @return true if the stick is pushed right
 */
bool controllerStickRight();

/**Check if the face button A was pressed. Maps to SPACE on keyboard.
 * @return true if the A button is pressed
 */
bool controllerButtonA();
/**Check if the face button B was pressed. Maps to J on keyboard.
 * @return true if the B button is pressed
 */
bool controllerButtonB();
/**Check if the face button C was pressed (X on xbox controller). Maps to K on keyboard.
 * @return true if the C button is pressed
 */
bool controllerButtonC();
/**Check if the face button D was pressed (Y on xbox controller). Maps to L on keyboard.
 * @return true if the D button is pressed
 */
bool controllerButtonD();

/**Called only when the program closes to clean up controller bits
 * /
 */
void controllerShutdown();
