#ifndef IMU_SPI_H__
#define IMU_SPI_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "Nano100Series.h"
#include "fih_arg.h"

#define SPI_IMU_PORT  SPI1
#define SPI_WRITE_TX    SPI_WRITE_TX0
#define SPI_READ_RX     SPI_READ_RX0

#define SPI_IMU_CS0     PC8
#define SPI_IMU_CS1     PB9
#define SPI_IMU_CS2     PB11
#define SPI_IMU_CLK     PC9
#define SPI_IMU_MOSI    PC11
#define SPI_IMU_MISO    PC10

#define BMM050_DIG_X1                      (0x5D)
#define BMM050_DIG_Y1                      (0x5E)
#define BMM050_DIG_Z4_LSB                  (0x62)
#define BMM050_DIG_Z4_MSB                  (0x63)
#define BMM050_DIG_X2                      (0x64)
#define BMM050_DIG_Y2                      (0x65)
#define BMM050_DIG_Z2_LSB                  (0x68)
#define BMM050_DIG_Z2_MSB                  (0x69)
#define BMM050_DIG_Z1_LSB                  (0x6A)
#define BMM050_DIG_Z1_MSB                  (0x6B)
#define BMM050_DIG_XYZ1_LSB                (0x6C)
#define BMM050_DIG_XYZ1_MSB                (0x6D)
#define BMM050_DIG_Z3_LSB                  (0x6E)
#define BMM050_DIG_Z3_MSB                  (0x6F)
#define BMM050_DIG_XY2                     (0x70)
#define BMM050_DIG_XY1                     (0x71)

#define	BMM050_DATA_FRAME_SIZE		(8)
#define	BMM050_INIT_DATA_SIZE		(2)
#define	BMM050_CHIP_ID_DATA			(0)
#define	BMM050_SELFTEST_DATA_SIZE	(5)
#define	BMM050_TRIM_DATA_SIZE		(2)
#define	BMM050_XLSB_DATA			(0)
#define	BMM050_XMSB_DATA			(1)
#define	BMM050_YLSB_DATA			(2)
#define	BMM050_YMSB_DATA			(3)
#define	BMM050_ZLSB_DATA			(4)
#define	BMM050_ZMSB_DATA			(5)
#define	BMM050_RLSB_DATA			(6)
#define	BMM050_RMSB_DATA			(7)
#define	BMM050_TRIM_DIG_Z1_LSB_DATA	(0)
#define	BMM050_TRIM_DIG_Z1_MSB_DATA	(1)
#define	BMM050_TRIM_DIG_Z2_LSB_DATA	(0)
#define	BMM050_TRIM_DIG_Z2_MSB_DATA	(1)
#define	BMM050_TRIM_DIG_Z3_LSB_DATA	(0)
#define	BMM050_TRIM_DIG_Z3_MSB_DATA	(1)
#define	BMM050_TRIM_DIG_Z4_LSB_DATA	(0)
#define	BMM050_TRIM_DIG_Z4_MSB_DATA	(1)
#define	BMM050_TRIM_DIG_XYZ1_LSB_DATA	(0)
#define	BMM050_TRIM_DIG_XYZ1_MSB_DATA	(1)
#define	BMM050_REMAPPED_YLSB_DATA			(0)
#define	BMM050_REMAPPED_YMSB_DATA			(1)
#define	BMM050_REMAPPED_XLSB_DATA			(2)
#define	BMM050_REMAPPED_XMSB_DATA			(3)

#define BMM050_DR_10HZ                     (0)
#define BMM050_DR_02HZ                     (1)
#define BMM050_DR_06HZ                     (2)
#define BMM050_DR_08HZ                     (3)
#define BMM050_DR_15HZ                     (4)
#define BMM050_DR_20HZ                     (5)
#define BMM050_DR_25HZ                     (6)
#define BMM050_DR_30HZ                     (7)

#define BMM050_PRESETMODE_LOWPOWER                  (1)
#define BMM050_PRESETMODE_REGULAR                   (2)
#define BMM050_PRESETMODE_HIGHACCURACY              (3)
#define BMM050_PRESETMODE_ENHANCED                  (4)

#define BMM050_LOWPOWER_REPZ                      (2)
#define BMM050_REGULAR_REPZ                      (14)
#define BMM050_HIGHACCURACY_REPZ                 (82)
#define BMM050_ENHANCED_REPZ                     (26)

#define BMM050_OVERFLOW_OUTPUT_FLOAT	0.0f

#define BMM050_REP_XY                      (0x51)
#define BMM050_REP_Z                       (0x52)

#define BMM050_LOWPOWER_DR                       (BMM050_DR_10HZ)
#define BMM050_REGULAR_DR                        (BMM050_DR_10HZ)
#define BMM050_HIGHACCURACY_DR                   (BMM050_DR_20HZ)
#define BMM050_ENHANCED_DR                       (BMM050_DR_10HZ)

#define BMM050_LOWPOWER_REPXY                     (1)
#define BMM050_REGULAR_REPXY                      (4)
#define BMM050_HIGHACCURACY_REPXY                (23)
#define BMM050_ENHANCED_REPXY                     (7)

#define BMM050_INIT_VALUE	0
#define BMM050_FLIP_OVERFLOW_ADCVAL		-4096
#define BMM050_HALL_OVERFLOW_ADCVAL		-16384
#define BMM050_NULL                 	((uint8_t)0)
#define E_BMM050_NULL_PTR           	((int8_t)-127)
#define ERROR							((int8_t)-1)
#define E_BMM050_OUT_OF_RANGE       	((int8_t)-2)
#define BMM050_NORMAL_MODE         		(0x00)
#define BMM050_SUSPEND_MODE         	(0x02)
#define BMM050_DELAY_SUSPEND_SLEEP		(3)
#define BMM050_CONTROL                   (0x4C)
#define BMM050_POWER_CONTROL               (0x4B)
#define BMM050_MDELAY_DATA_TYPE			  uint32_t
#define BMM050_PRESETMODE_REGULAR		(2)

#define BMM050_CONTROL_OPERATION_MODE__POS            (1)
#define BMM050_CONTROL_OPERATION_MODE__LEN            (2)
#define BMM050_CONTROL_OPERATION_MODE__MSK            (0x06)
#define BMM050_CONTROL_OPERATION_MODE__REG            (BMM050_CONTROL)
#define BMM050_CONTROL_DATA_RATE__POS                (3)
#define BMM050_CONTROL_DATA_RATE__LEN                (3)
#define BMM050_CONTROL_DATA_RATE__MSK                (0x38)
#define BMM050_CONTROL_DATA_RATE__REG                (BMM050_CONTROL)
#define BMM050_POWER_CONTROL_POWER_CONTROL_BIT__POS         (0)
#define BMM050_POWER_CONTROL_POWER_CONTROL_BIT__LEN         (1)
#define BMM050_POWER_CONTROL_POWER_CONTROL_BIT__MSK         (0x01)
#define BMM050_POWER_CONTROL_POWER_CONTROL_BIT__REG         \
(BMM050_POWER_CONTROL)

/* Data Registers*/
#define BMM050_DATA_X_LSB	0x42
#define BMM050_DATA_X_MSB	0x43
#define BMM050_DATA_Y_LSB	0x44
#define BMM050_DATA_Y_MSB	0x45
#define BMM050_DATA_Z_LSB	0x46
#define BMM050_DATA_Z_MSB	0x47
#define BMM050_DATA_R_LSB	0x48
#define BMM050_DATA_R_MSB	0x49

/* Data X LSB Register */
#define BMM050_DATA_X_LSB_BIT__POS	3
#define BMM050_DATA_X_LSB_BIT__LEN	5
#define BMM050_DATA_X_LSB_BIT__MSK	0xF8
#define BMM050_DATA_X_LSB_BIT__REG	BMM050_DATA_X_LSB

/* Data Y LSB Register */
#define BMM050_DATA_Y_LSB_BIT__POS	3
#define BMM050_DATA_Y_LSB_BIT__LEN	5
#define BMM050_DATA_Y_LSB_BIT__MSK	0xF8
#define BMM050_DATA_Y_LSB_BIT__REG	BMM050_DATA_Y_LSB

/* Data Z LSB Register */
#define BMM050_DATA_Z_LSB_BIT__POS	1
#define BMM050_DATA_Z_LSB_BIT__LEN	7
#define BMM050_DATA_Z_LSB_BIT__MSK	0xFE
#define BMM050_DATA_Z_LSB_BIT__REG	BMM050_DATA_Z_LSB

/* Hall Resistance LSB Register */
#define BMM050_DATA_R_LSB_BIT__POS	2
#define BMM050_DATA_R_LSB_BIT__LEN	6
#define BMM050_DATA_R_LSB_BIT__MSK	0xFC
#define BMM050_DATA_R_LSB_BIT__REG	BMM050_DATA_R_LSB

#define BMM050_DATA_RDYSTAT__POS	0
#define BMM050_DATA_RDYSTAT__LEN	1
#define BMM050_DATA_RDYSTAT__MSK	0x01
#define BMM050_DATA_RDYSTAT__REG	BMM050_DATA_R_LSB

#define BMM050_DIG_XYZ1_MSB__POS         (0)
#define BMM050_DIG_XYZ1_MSB__LEN         (7)
#define BMM050_DIG_XYZ1_MSB__MSK         (0x7F)
#define BMM050_DIG_XYZ1_MSB__REG         (BMM050_DIG_XYZ1_MSB)
/* get bit slice  */
#define BMM050_GET_BITSLICE(regvar, bitname) ((regvar & bitname##__MSK) >> bitname##__POS)
#define BMM050_SET_BITSLICE(regvar, bitname, val) ((regvar & ~bitname##__MSK) | ((val<<bitname##__POS)&bitname##__MSK))

typedef struct bma2x2_accel_data {
				uint16_t acc_x, acc_y, acc_z;
} bma2x2_acc_data;

typedef struct bmg160_data_t {
				uint16_t gyro_x, gyro_y, gyro_z;
}bmg160_gyro_data;


typedef struct bmm050_data_t {
	int8_t dig_x1,dig_y1,dig_x2,dig_y2;

	uint16_t dig_z1;/**< trim z1 data */
	int16_t dig_z2,dig_z3,dig_z4;/**< trim z4 data */

	uint8_t dig_xy1,dig_xy2;/**< trim xy2 data */

	uint16_t dig_xyz1;/**< trim xyz1 data */
}bmm050_t;

typedef struct bmm050_mag_data_float_t {
				float mag_x, mag_y, mag_z;
}bmm050_mag_data;

extern void Spi_WriteReg_Gyro(uint8_t reg, uint8_t u8Value);
extern void Spi_WriteReg_Acc(uint8_t reg, uint8_t u8Value);
extern void Spi_WriteReg_Mag(uint8_t reg, uint8_t u8Value);
extern uint8_t Spi_ReadReg_Gyro(uint8_t reg);
//extern uint8_t Spi_ReadReg_Mag(uint8_t reg);
extern int8_t Spi_ReadReg_Mag(uint8_t reg);
extern uint8_t Spi_ReadReg_Acc(uint8_t reg);
extern void Imu_Spi1_Init(void);
extern void read_imu_chip_id(void);
//extern void init_imu_chip(void);
extern void init_imu_chip(bmm050_t *bmm050);
extern void Imu_Read_Data(void);

extern void Imu_Acc_Raw(bma2x2_acc_data *accel);
extern void Imu_Gyro_Raw(bmg160_gyro_data *gyro);
extern void Imu_Mag_Raw(bmm050_mag_data *mag);
#ifdef __cplusplus
}
#endif

#endif

