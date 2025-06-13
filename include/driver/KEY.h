/*
 * KEY.h
 *
 *  Created on: 12 jun. 2025
 *      Author: Usuario
 */

#ifndef DRIVER_KEY_H_
#define DRIVER_KEY_H_

typedef enum {
  KEY_NA = 0,
  KEY_A,
  KEY_B,
  KEY_C,
  KEY_MAX,
} Key_types;

typedef enum {
    MODE_NOCONT,
    MODE_CONT,
} Mode_types;

typedef enum {
    KSTATUS_NOPRESS,
    KSTATUS_B1_PRESS,
    KSTATUS_B2_PRESS,
    KSTATUS_B3_PRESS,
} KeyStatus_types;

/*
 * @brief KEY Initialization
 */
void KEY_Init(void);

/*
 * @brief: Get key value
 * @param: mode: MODE_NOCONT, does not support continuous pressing; MODE_CONT,
 *               supports continuous pressing.
 * @return: KeyStatus_types, KSTATUS_NOPRESS: No button pressed KSTATUS_B1_PRESS:
 *          Button 1 pressed KSTATUS_B2_PRESS: Button 2 pressed KSTATUS_B3_PRESS:
 *          Button 3 pressed
 */
KeyStatus_types KEY_Read(Mode_types mode, Key_types key);

/*
 * @brief: Key Test Procedure
 */
void Test_KEY(void);


#endif /* DRIVER_KEY_H_ */
