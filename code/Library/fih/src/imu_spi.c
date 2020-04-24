#include <stdio.h>
#include "Nano100Series.h"
#include "fih_arg.h"

static bmm050_t *p_bmm050;

void Spi_WriteReg_Gyro(uint8_t reg, uint8_t u8Value)
{
    SPI_IMU_CS1 = 1;
    SPI_IMU_CS2 = 1;
    SPI_IMU_CS0 = 0;
    
    // send Command: register num
	SPI_WRITE_TX(SPI_IMU_PORT, (reg << 8) | u8Value);
	SPI_TRIGGER(SPI1);
    while(SPI_IS_BUSY(SPI_IMU_PORT));

    SPI_IMU_CS0 = 1;
}
void Spi_WriteReg_Acc(uint8_t reg, uint8_t u8Value)
{
    SPI_IMU_CS0 = 1;
    SPI_IMU_CS2 = 1;
    SPI_IMU_CS1 = 0;
    
    // send Command: register num
	SPI_WRITE_TX(SPI_IMU_PORT, (reg << 8) | u8Value);
	SPI_TRIGGER(SPI1);
    while(SPI_IS_BUSY(SPI_IMU_PORT));

    SPI_IMU_CS1 = 1;
}
void Spi_WriteReg_Mag(uint8_t reg, uint8_t u8Value)
{
    SPI_IMU_CS0 = 1;
    SPI_IMU_CS1 = 1;
    SPI_IMU_CS2 = 0;
    
    // send Command: register num
	SPI_WRITE_TX(SPI_IMU_PORT, (reg << 8) | u8Value);
	SPI_TRIGGER(SPI1);
    while(SPI_IS_BUSY(SPI_IMU_PORT));

    SPI_IMU_CS2 = 1;
}
uint8_t Spi_ReadReg_Gyro(uint8_t reg)
{
	uint8_t ReturnValue;

    SPI_IMU_CS1 = 1;
    SPI_IMU_CS2 = 1;
    SPI_IMU_CS0 = 0;

    // send Command: register num
    SPI_WRITE_TX(SPI_IMU_PORT, (reg | 0x80) << 8 | 0x00);
	SPI_TRIGGER(SPI1);
    while(SPI_IS_BUSY(SPI_IMU_PORT));
    SPI_IMU_CS0 = 1;

	ReturnValue = (SPI_READ_RX(SPI_IMU_PORT) & 0xff);
#ifdef IMU_SPI_DEBUG
	printf("Gyro reg = %x, Value = %x\n",reg, ReturnValue);
#endif
	return ReturnValue;
}
//uint8_t Spi_ReadReg_Mag(uint8_t reg)
int8_t Spi_ReadReg_Mag(uint8_t reg)
{
	int8_t ReturnValue;

    SPI_IMU_CS0 = 1;
    SPI_IMU_CS1 = 1;
    SPI_IMU_CS2 = 0;

    // send Command: register num
    SPI_WRITE_TX(SPI_IMU_PORT, (reg | 0x80) << 8 | 0x00);
	SPI_TRIGGER(SPI1);
    while(SPI_IS_BUSY(SPI_IMU_PORT));

    SPI_IMU_CS2 = 1;

	ReturnValue = (SPI_READ_RX(SPI_IMU_PORT) & 0xff);
#ifdef IMU_SPI_DEBUG
	printf("Mag reg = %x, Value = %x\n",reg, ReturnValue);
#endif

	return ReturnValue;
}
uint8_t Spi_ReadReg_Acc(uint8_t reg)
{
	uint8_t ReturnValue;

    SPI_IMU_CS0 = 1;
    SPI_IMU_CS2 = 1;
    SPI_IMU_CS1 = 0;

    // send Command: register num
    SPI_WRITE_TX(SPI_IMU_PORT, (reg | 0x80) << 8 | 0x00);
	SPI_TRIGGER(SPI1);
    while(SPI_IS_BUSY(SPI_IMU_PORT));

    SPI_IMU_CS1 = 1;

	ReturnValue = (SPI_READ_RX(SPI_IMU_PORT) & 0xff);
#ifdef IMU_SPI_DEBUG
	printf("Acc reg = %x, Value = %x\n",reg, ReturnValue);
#endif

	return ReturnValue;
}

void Imu_Spi1_Init(void)
{
	SYS_UnlockReg();
	CLK_SetModuleClock(SPI1_MODULE, CLK_CLKSEL2_SPI1_S_PLL, 1);
	CLK_EnableModuleClock(SPI1_MODULE);
	SYS->PC_H_MFP &= ~(SYS_PC_H_MFP_PC9_MFP_Msk | SYS_PC_H_MFP_PC10_MFP_Msk | SYS_PC_H_MFP_PC11_MFP_Msk);
	SYS->PC_H_MFP = (SYS_PC_H_MFP_PC9_MFP_SPI1_SCLK | SYS_PC_H_MFP_PC10_MFP_SPI1_MISO0 | SYS_PC_H_MFP_PC11_MFP_SPI1_MOSI0);	
	SYS_LockReg();
	
	GPIO_SetMode(PC, BIT8, GPIO_PMD_OUTPUT);
	GPIO_SetMode(PB, BIT11, GPIO_PMD_OUTPUT);
    GPIO_SetMode(PB, BIT9, GPIO_PMD_OUTPUT);
	PC8 = 1;
	PB11 = 1;
    PB9 = 1;
	
	SPI_Open(SPI_IMU_PORT, SPI_MASTER, SPI_MODE_3, 16, 400000);
	
	SPI_SET_MSB_FIRST(SPI_IMU_PORT);
	
}

void bmm050_get_data_rate(uint8_t *v_data_rate_u8)
{
	/* variable used to return the bus communication result*/
	int8_t com_rslt = ERROR;
	uint8_t v_data_u8 = BMM050_INIT_VALUE;

	com_rslt = Spi_ReadReg_Mag(0x4C);
	*v_data_rate_u8 = BMM050_GET_BITSLICE(v_data_u8,BMM050_CONTROL_DATA_RATE);

}

void bmm050_set_data_rate(uint8_t v_data_rate_u8)
{
	/* variable used to return the bus communication result*/
	int8_t com_rslt = ERROR;
	uint8_t v_data_u8 = BMM050_INIT_VALUE;

	/* set the data rate */
	com_rslt = Spi_ReadReg_Mag(0x4C);

	v_data_u8 = BMM050_SET_BITSLICE(v_data_u8,BMM050_CONTROL_DATA_RATE, v_data_rate_u8);
			
	Spi_WriteReg_Mag(BMM050_CONTROL_DATA_RATE__REG,v_data_u8);
}

void bmm050_set_rep_XY(uint8_t v_rep_xy_u8)
{
	/* variable used to return the bus communication result*/
	int8_t com_rslt = ERROR;
	uint8_t v_data_u8 = BMM050_INIT_VALUE;

		/* write XY repetitions*/
		v_data_u8 = v_rep_xy_u8;
		Spi_WriteReg_Mag(BMM050_REP_XY,v_data_u8);

}

void bmm050_set_rep_Z(uint8_t v_rep_z_u8)
{
	/* variable used to return the bus communication result*/
	int8_t com_rslt = ERROR;
	uint8_t v_data_u8 = BMM050_INIT_VALUE;

		/* write Z repetitions*/
		v_data_u8 = v_rep_z_u8;
		Spi_WriteReg_Mag(BMM050_REP_Z,v_data_u8);

}

void bmm050_get_power_mode(uint8_t *v_power_mode_u8)
{
	/* variable used to return the bus communication result*/
	int8_t com_rslt = ERROR;
	uint8_t v_data_u8 = BMM050_INIT_VALUE;

		/* read power control bit */
		com_rslt = Spi_ReadReg_Mag(0x4B);
		//printf("get_power_mode1=%x\n",com_rslt);
			
		if (!com_rslt) {
			*v_power_mode_u8 = BMM050_GET_BITSLICE(v_data_u8,BMM050_POWER_CONTROL_POWER_CONTROL_BIT);
		}
}

void bmm050_set_power_mode(uint8_t v_power_mode_u8)
{
	/* variable used to return the bus communication result*/
	int8_t com_rslt = ERROR;
	uint8_t v_data_u8 = BMM050_INIT_VALUE;
	
		v_data_u8 = Spi_ReadReg_Mag(0x4B);
	
		v_data_u8 = BMM050_SET_BITSLICE(v_data_u8,BMM050_POWER_CONTROL_POWER_CONTROL_BIT, v_power_mode_u8);

		Spi_WriteReg_Mag(0x4B,0x01);
	
		v_data_u8 = Spi_ReadReg_Mag(0x4B);
}

int8_t bmm050_set_functional_state(uint8_t v_functional_state_u8)
{
	/* variable used to return the bus communication result*/
	int8_t com_rslt = ERROR;
	uint8_t v_data_u8 = BMM050_INIT_VALUE;

		/* select the functional state*/
		switch (v_functional_state_u8) {
		/* write the functional state*/
		case BMM050_NORMAL_MODE:
			bmm050_get_power_mode(&v_data_u8);
		
			if (v_data_u8 == 0x0) 
			{
				bmm050_set_power_mode(1);
				delay_ms(3);
			}
			
			v_data_u8 = Spi_ReadReg_Mag(BMM050_CONTROL_OPERATION_MODE__REG);
			v_data_u8 = BMM050_SET_BITSLICE(v_data_u8,BMM050_CONTROL_OPERATION_MODE,BMM050_NORMAL_MODE);
			
			Spi_WriteReg_Mag(BMM050_CONTROL_OPERATION_MODE__REG,v_data_u8);
			break;
		case BMM050_SUSPEND_MODE:
			bmm050_set_power_mode(0);
			break;
		default:
			com_rslt = E_BMM050_OUT_OF_RANGE;
			break;
		}

	return com_rslt;
}

int8_t bmm050_init_trim_registers(void)
{
	/* variable used to return the bus communication result*/
	int8_t com_rslt = ERROR;

	uint8_t v_data_u8[BMM050_TRIM_DATA_SIZE] = {BMM050_INIT_VALUE, BMM050_INIT_VALUE};
	
	p_bmm050->dig_x1 = Spi_ReadReg_Mag(BMM050_DIG_X1);
	
	p_bmm050->dig_y1 = Spi_ReadReg_Mag(BMM050_DIG_Y1);
	
	p_bmm050->dig_x2 = Spi_ReadReg_Mag(BMM050_DIG_X2);
	
	p_bmm050->dig_y2 = Spi_ReadReg_Mag(BMM050_DIG_Y2);
	
	p_bmm050->dig_xy1 = Spi_ReadReg_Mag(BMM050_DIG_XY1);
	
	p_bmm050->dig_xy2 = Spi_ReadReg_Mag(BMM050_DIG_XY2);
	
	/* shorts can not be recast into (u8*)
	* due to possible mix up between trim data
	* arrangement and memory arrangement */
	
	v_data_u8[0] = Spi_ReadReg_Mag(BMM050_DIG_Z1_LSB);
	v_data_u8[1] = Spi_ReadReg_Mag(BMM050_DIG_Z1_MSB);
	p_bmm050->dig_z1 = (uint16_t)((((uint32_t)((uint8_t)v_data_u8[1])) << 8) | v_data_u8[0]);


	v_data_u8[0] = Spi_ReadReg_Mag(BMM050_DIG_Z2_LSB);
	v_data_u8[1] = Spi_ReadReg_Mag(BMM050_DIG_Z2_MSB);
	p_bmm050->dig_z2 = (int16_t)((((int32_t)((int8_t)v_data_u8[1])) << 8) | v_data_u8[0]);

	v_data_u8[0] = Spi_ReadReg_Mag(BMM050_DIG_Z3_LSB);
	v_data_u8[1] = Spi_ReadReg_Mag(BMM050_DIG_Z3_MSB);
	p_bmm050->dig_z3 = (int16_t)((((int32_t)((int8_t)v_data_u8[1])) << 8) | v_data_u8[0]);
	

	v_data_u8[0] = Spi_ReadReg_Mag(BMM050_DIG_Z4_LSB);
	v_data_u8[1] = Spi_ReadReg_Mag(BMM050_DIG_Z4_MSB);
	p_bmm050->dig_z4 = (int16_t)((((int32_t)((int8_t)v_data_u8[1])) << 8) | v_data_u8[0]);
	
	v_data_u8[0] = Spi_ReadReg_Mag(BMM050_DIG_XYZ1_LSB);
	v_data_u8[1] = Spi_ReadReg_Mag(BMM050_DIG_XYZ1_MSB);
	
	v_data_u8[BMM050_TRIM_DIG_XYZ1_MSB_DATA] = BMM050_GET_BITSLICE(v_data_u8[BMM050_TRIM_DIG_XYZ1_MSB_DATA],BMM050_DIG_XYZ1_MSB);
	
	p_bmm050->dig_xyz1 = (uint16_t)((((uint32_t)((uint8_t)v_data_u8[1])) << 8) | v_data_u8[0]);
	
	return com_rslt;
}

int8_t bmm050_set_presetmode(uint8_t v_presetmode_u8)
{
	/* variable used to return the bus communication result*/
	int8_t com_rslt = ERROR;

	switch (v_presetmode_u8) {
	case BMM050_PRESETMODE_LOWPOWER:
		/* Set the data rate for Low Power mode */
		bmm050_set_data_rate(BMM050_LOWPOWER_DR);
		/* Set the XY-repetitions number for Low Power mode */
		bmm050_set_rep_XY(BMM050_LOWPOWER_REPXY);
		/* Set the Z-repetitions number  for Low Power mode */
		bmm050_set_rep_Z(BMM050_LOWPOWER_REPZ);	
		break;
	case BMM050_PRESETMODE_REGULAR:
		/* Set the data rate for Regular mode */
		bmm050_set_data_rate(BMM050_REGULAR_DR);
		/* Set the XY-repetitions number for Regular mode */
		bmm050_set_rep_XY(BMM050_REGULAR_REPXY);
		/* Set the Z-repetitions number  for Regular mode */
		bmm050_set_rep_Z(BMM050_REGULAR_REPZ);
		break;
	case BMM050_PRESETMODE_HIGHACCURACY:
		/* Set the data rate for High Accuracy mode */
		bmm050_set_data_rate(BMM050_HIGHACCURACY_DR);
		/* Set the XY-repetitions number for High Accuracy mode */
		bmm050_set_rep_XY(BMM050_HIGHACCURACY_REPXY);
		/* Set the Z-repetitions number  for High Accuracy mode */
		bmm050_set_rep_Z(BMM050_HIGHACCURACY_REPZ);
		break;
	case BMM050_PRESETMODE_ENHANCED:
		/* Set the data rate for Enhanced Accuracy mode */
		bmm050_set_data_rate(BMM050_ENHANCED_DR);
		/* Set the XY-repetitions number for High Enhanced mode */
		bmm050_set_rep_XY(BMM050_ENHANCED_REPXY);
		/* Set the Z-repetitions number  for High Enhanced mode */
		bmm050_set_rep_Z(BMM050_ENHANCED_REPZ);
		break;
	default:
		com_rslt = E_BMM050_OUT_OF_RANGE;
		break;
	}
	return com_rslt;
}

float bmm050_compensate_X_float(int16_t mag_data_x, uint16_t data_r)
{
	float inter_retval = BMM050_INIT_VALUE;

	if (mag_data_x != BMM050_FLIP_OVERFLOW_ADCVAL	/* no overflow */)
	{
		if ((data_r != BMM050_INIT_VALUE) && (p_bmm050->dig_xyz1 != BMM050_INIT_VALUE))
		{
			inter_retval = ((((float)p_bmm050->dig_xyz1) * 16384.0 / data_r) - 16384.0);
		} else {
			inter_retval = BMM050_OVERFLOW_OUTPUT_FLOAT;
			return inter_retval;
		}
		
		inter_retval = (((mag_data_x * ((((((float)p_bmm050->dig_xy2) * (inter_retval*inter_retval / 268435456.0) + inter_retval * ((float)p_bmm050->dig_xy1) / 16384.0)) + 256.0) * (((float)p_bmm050->dig_x2) + 160.0))) / 8192.0) + (((float)p_bmm050->dig_x1) * 8.0)) / 16.0;
	} else {
		inter_retval = BMM050_OVERFLOW_OUTPUT_FLOAT;
	}
	
	return inter_retval;
}

float bmm050_compensate_Y_float(int16_t mag_data_y, uint16_t data_r)
{
	float inter_retval = BMM050_INIT_VALUE;


	if (mag_data_y != BMM050_FLIP_OVERFLOW_ADCVAL)
	{
		if ((data_r != BMM050_INIT_VALUE) && (p_bmm050->dig_xyz1 != BMM050_INIT_VALUE))
		{
			inter_retval = ((((float)p_bmm050->dig_xyz1) * 16384.0 /data_r) - 16384.0);
		} else {
			inter_retval = BMM050_OVERFLOW_OUTPUT_FLOAT;
			return inter_retval;
		}
		inter_retval = (((mag_data_y * ((((((float)p_bmm050->dig_xy2) * (inter_retval*inter_retval / 268435456.0) + inter_retval * ((float)p_bmm050->dig_xy1) / 16384.0)) + 256.0) * (((float)p_bmm050->dig_y2) + 160.0))) / 8192.0) + (((float)p_bmm050->dig_y1) * 8.0)) / 16.0;
	} else {
		/* overflow, set output to 0.0f */
		inter_retval = BMM050_OVERFLOW_OUTPUT_FLOAT;
	}
	
	return inter_retval;
}

float bmm050_compensate_Z_float (int16_t mag_data_z, uint16_t data_r)
{
	float inter_retval = BMM050_INIT_VALUE;

	 /* no overflow */
	if (mag_data_z != BMM050_HALL_OVERFLOW_ADCVAL)
	{
		if ((p_bmm050->dig_z2 != BMM050_INIT_VALUE) && (p_bmm050->dig_z1 != BMM050_INIT_VALUE) && (p_bmm050->dig_xyz1 != BMM050_INIT_VALUE) && (data_r != BMM050_INIT_VALUE))
		{
			inter_retval = ((((((float)mag_data_z) - ((float)p_bmm050->dig_z4)) * 131072.0) - (((float)p_bmm050->dig_z3) * (((float)data_r) - ((float)p_bmm050->dig_xyz1)))) / ((((float)p_bmm050->dig_z2) + ((float)p_bmm050->dig_z1)*((float)data_r) / 32768.0) * 4.0)) / 16.0;
		}
	} else {
		/* overflow, set output to 0.0f */
		inter_retval = BMM050_OVERFLOW_OUTPUT_FLOAT;
	}
	
	return inter_retval;
}

void bmm050_init(bmm050_t *bmm050)
{
	/* variable used to return the bus communication result*/
	int8_t com_rslt = ERROR;
	/*Array holding the mag chip id
	v_data_u8[0] - chip id
	*/
	uint8_t v_data_u8[2] = {BMM050_INIT_VALUE, BMM050_INIT_VALUE};

	//p_bmm050 = bmm050;

	/* set device from suspend into sleep mode */
	bmm050_set_power_mode(1);

	delay_ms(3);

	/*Read CHIP_ID and REv. info */
	v_data_u8[0] = Spi_ReadReg_Mag(0x40);
	
	printf("company_id=%d\n",v_data_u8[0]);

	/* Function to initialise trim values */
	com_rslt += bmm050_init_trim_registers();
	/* set the preset mode as regular*/
	com_rslt += bmm050_set_presetmode(BMM050_PRESETMODE_REGULAR);
}

void read_imu_chip_id(void)
{
    uint8_t ret;

	ret = Spi_ReadReg_Gyro(0x00);
	delay_ms(20);
    ret = Spi_ReadReg_Acc(0x00);
    delay_ms(20);
		
    ret = Spi_ReadReg_Mag(0x4B);
	
#ifdef IMU_SPI_DEBUG
    printf("mag 111   0x4B val is %x\n",ret);
#endif  
	
    Spi_WriteReg_Mag(0x4B,(0x01 | ret));
    ret = Spi_ReadReg_Mag(0x4B);
	
#ifdef IMU_SPI_DEBUG
    printf("mag 222 0x4B val is %x\n",ret);
#endif
        
    delay_ms(20);
}

void init_imu_chip(bmm050_t *bmm050)
{
	uint8_t ret;
	uint8_t i = 0;
	
	uint8_t v_data_rate_u8 = BMM050_INIT_VALUE;

	int32_t com_rslt = ERROR;

	uint8_t v_data_u8[2] = {BMM050_INIT_VALUE, BMM050_INIT_VALUE};
	
	Spi_WriteReg_Gyro(0x10,0x7);
#ifdef IMU_SPI_DEBUG
	ret = Spi_ReadReg_Gyro(0x10);
	printf("Gyro 0X10 val is %x\n",ret);
#endif

	delay_ms(1);

	Spi_WriteReg_Acc(0x10,0xA);
#ifdef IMU_SPI_DEBUG
	ret = Spi_ReadReg_Acc(0x10);
	printf("Acc 0X10 val is %x\n",ret);
#endif

	//bmm050_init(&bmm050);
	
	p_bmm050 = bmm050;

	/* set device from suspend into sleep mode */
	bmm050_set_power_mode(1);

	delay_ms(3);

	/*Read CHIP_ID and REv. info */
	v_data_u8[0] = Spi_ReadReg_Mag(0x40);
#ifdef IMU_SPI_DEBUG
	printf("company_id=%d\n",v_data_u8[0]);
#endif
	//p_bmm050->company_id = v_data_u8[0];

	/* Function to initialise trim values */
	com_rslt += bmm050_init_trim_registers();
	/* set the preset mode as regular*/
	com_rslt += bmm050_set_presetmode(BMM050_PRESETMODE_REGULAR);
	

	/* Set the power mode as NORMAL*/
	com_rslt = bmm050_set_functional_state(BMM050_NORMAL_MODE);
#ifdef IMU_SPI_DEBUG
	printf("set_functional_state is %x\n",com_rslt);
#endif

	/* This API used to Write the data rate of the sensor, input
	value have to be given
	data rate value set from the register 0x4C bit 3 to 5*/
	bmm050_set_data_rate(0x07);/* set data rate of 30Hz*/

	/* This API used to read back the written value of data rate*/
	bmm050_get_data_rate(&v_data_rate_u8);


	/* accessing the bmm050_mdata_float parameter by using data_float*/
	/* Reads mag xyz data output as 32bit value*/
	//com_rslt = bmm050_read_mag_data_XYZ_float(&data_float);
	//printf("read_mag_data_XYZ_float is %x\n",com_rslt);

	//com_rslt = bmm050_set_functional_state(BMM050_SUSPEND_MODE);
	
}

void Imu_Gyro_Raw(bmg160_gyro_data *gyro)
{ 
	uint8_t i = 0;
	uint8_t gy_data[10];
	uint8_t ret;
	
	ret = Spi_ReadReg_Gyro(0x0F);
	
#ifdef IMU_SPI_DEBUG
    printf("Gyro 0x0F val is %x\n",ret);
#endif
	
    for(i = 2; i < 8; i++)
    {
        gy_data[i] = Spi_ReadReg_Gyro(i);
    }
		
    gyro->gyro_x = (gy_data[3] << 8) | gy_data[2];
    gyro->gyro_y = (gy_data[5] << 8) | gy_data[4];
    gyro->gyro_z = (gy_data[7] << 8) | gy_data[6];

#ifdef IMU_SPI_DEBUG
    printf("Gyro x = %x, y = %x, z = %x\n",gyro->gyro_x,gyro->gyro_y,gyro->gyro_z);
#endif
}

void Imu_Acc_Raw(bma2x2_acc_data *accel)
{
	uint8_t i = 0;
	uint8_t acc[10];
#if 0
	uint16_t accell; 
		
	uint8_t j,k,l,m = 0;
	
	j = sizeof(uint8_t);
	k = sizeof(uint16_t);
	l = sizeof(int8_t);
	m = sizeof(int16_t);
	
	printf(" j=%d,k=%d,l=%d,m=%d\n",j,k,l,m);
#endif
	
    for(i = 2; i < 8; i++)
    {
        acc[i] = Spi_ReadReg_Acc(i);
    }

	accel->acc_x = (int16_t)((((int32_t)((int8_t)acc[3])) << 8) | (acc[2] & 0xF0)) >> 4;
	accel->acc_y = (int16_t)((((int32_t)((int8_t)acc[5])) << 8) | (acc[4] & 0xF0)) >> 4;
	accel->acc_z = (int16_t)((((int32_t)((int8_t)acc[7])) << 8) | (acc[6] & 0xF0)) >> 4;
	
#ifdef IMU_SPI_DEBUG
    printf(" Acc x = %x, y = %x, z = %x\n",accel->acc_x,accel->acc_y,accel->acc_z);
#endif
}

void Imu_Mag_Raw(bmm050_mag_data *mag)
{ 
	uint8_t i,j = 0;
	
		/* variable used to return the bus communication result*/
	int8_t com_rslt = ERROR;
	uint8_t data_ready;

	uint8_t v_data_u8[BMM050_DATA_FRAME_SIZE] = {
	BMM050_INIT_VALUE, BMM050_INIT_VALUE,
	BMM050_INIT_VALUE, BMM050_INIT_VALUE,
	BMM050_INIT_VALUE, BMM050_INIT_VALUE,
	BMM050_INIT_VALUE, BMM050_INIT_VALUE};
	
	/* structure used to store the mag raw xyz and r data */
		struct {
		int16_t raw_data_x;
		int16_t raw_data_y;
		int16_t raw_data_z;
		int16_t raw_data_r;
	} raw_data_xyz_t;

	for(i=0x42;i<74;i++)
	{
		v_data_u8[j] = Spi_ReadReg_Mag(i);
		//printf("v_data_u8[j] = %x\n",v_data_u8[j]);
		j++;
	}
	
	/* Reading data for X axis */
	v_data_u8[0] = BMM050_GET_BITSLICE(v_data_u8[0], BMM050_DATA_X_LSB_BIT);
	raw_data_xyz_t.raw_data_x = (int16_t)((((int32_t)((int8_t)v_data_u8[1])) << 5) | v_data_u8[0]);

	/* Reading data for Y axis */
	v_data_u8[2] = BMM050_GET_BITSLICE(v_data_u8[2], BMM050_DATA_Y_LSB_BIT);
	raw_data_xyz_t.raw_data_y = (int16_t)((((int32_t)((int8_t)v_data_u8[3])) << 5) | v_data_u8[2]);

	/* Reading data for Z axis */
	v_data_u8[4] = BMM050_GET_BITSLICE(v_data_u8[4], BMM050_DATA_Z_LSB_BIT);
	raw_data_xyz_t.raw_data_z = (int16_t)((((int32_t)((int8_t)v_data_u8[5])) << 7)| v_data_u8[4]);

	/* read the data ready status*/
	data_ready = BMM050_GET_BITSLICE(v_data_u8[6],BMM050_DATA_RDYSTAT);

	/* Reading data for Resistance*/
	v_data_u8[6] =BMM050_GET_BITSLICE(v_data_u8[6], BMM050_DATA_R_LSB_BIT);
	raw_data_xyz_t.raw_data_r = (uint16_t)((((uint32_t)v_data_u8[7]) << 6)| v_data_u8[6]);

	/* Compensation for X axis */
	mag->mag_x = bmm050_compensate_X_float(raw_data_xyz_t.raw_data_x, raw_data_xyz_t.raw_data_r);

	/* Compensation for Y axis */
	mag->mag_y = bmm050_compensate_Y_float(raw_data_xyz_t.raw_data_y, raw_data_xyz_t.raw_data_r);

	/* Compensation for Z axis */
	mag->mag_z = bmm050_compensate_Z_float(raw_data_xyz_t.raw_data_z, raw_data_xyz_t.raw_data_r);
	
#ifdef IMU_SPI_DEBUG	
		printf("mag->mag_x = %f\n",mag->mag_x);
		printf("mag->mag_y = %f\n",mag->mag_y);
		printf("mag->mag_z = %f\n",mag->mag_z);
#endif
	/* Output raw resistance value */
	//mag->resistance = raw_data_xyz_t.raw_data_r;

}
