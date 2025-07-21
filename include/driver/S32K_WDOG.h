/*
 * S32K_WDOG.h
 *
 *  Created on: 18 jul. 2025
 *      Author: Usuario
 */

#ifndef DRIVER_S32K_WDOG_H_
#define DRIVER_S32K_WDOG_H_

/*
 * @brief Disable watchdog
 */
void WDOG_Disable(void);

/*
 * @brief Unlock watchdog
 */
void WDOG_Unlock(void);

/*
 * @brief: Enable once the watchdog
 * @param: TM: Timeout period, value range im ms [2,130]
 */
void WDOG_EnableOnce(uint16_t TM);

/*
 * @brief: Enable watchdog
 * @param: TM: Timeout period, value range im ms [2,130]
 */
void WDOG_Enable(uint16_t TM);

/*
 * @brief Refresh watchdog
 */
void WDOG_Refresh(void);


#endif /* DRIVER_S32K_WDOG_H_ */
