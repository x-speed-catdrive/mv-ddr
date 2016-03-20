/*******************************************************************************
Copyright (C) 2016 Marvell International Ltd.

This software file (the "File") is owned and distributed by Marvell
International Ltd. and/or its affiliates ("Marvell") under the following
alternative licensing terms.  Once you have made an election to distribute the
File under one of the following license alternatives, please (i) delete this
introductory statement regarding license alternatives, (ii) delete the three
license alternatives that you have not elected to use and (iii) preserve the
Marvell copyright notice above.

********************************************************************************
Marvell Commercial License Option

If you received this File from Marvell and you have entered into a commercial
license agreement (a "Commercial License") with Marvell, the File is licensed
to you under the terms of the applicable Commercial License.

********************************************************************************
Marvell GPL License Option

This program is free software: you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the Free
Software Foundation, either version 2 of the License, or any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

********************************************************************************
Marvell GNU General Public License FreeRTOS Exception

If you received this File from Marvell, you may opt to use, redistribute and/or
modify this File in accordance with the terms and conditions of the Lesser
General Public License Version 2.1 plus the following FreeRTOS exception.
An independent module is a module which is not derived from or based on
FreeRTOS.
Clause 1:
Linking FreeRTOS statically or dynamically with other modules is making a
combined work based on FreeRTOS. Thus, the terms and conditions of the GNU
General Public License cover the whole combination.
As a special exception, the copyright holder of FreeRTOS gives you permission
to link FreeRTOS with independent modules that communicate with FreeRTOS solely
through the FreeRTOS API interface, regardless of the license terms of these
independent modules, and to copy and distribute the resulting combined work
under terms of your choice, provided that:
1. Every copy of the combined work is accompanied by a written statement that
details to the recipient the version of FreeRTOS used and an offer by yourself
to provide the FreeRTOS source code (including any modifications you may have
made) should the recipient request it.
2. The combined work is not itself an RTOS, scheduler, kernel or related
product.
3. The independent modules add significant and primary functionality to
FreeRTOS and do not merely extend the existing functionality already present in
FreeRTOS.
Clause 2:
FreeRTOS may not be used for any competitive or comparative purpose, including
the publication of any form of run time or compile time metric, without the
express permission of Real Time Engineers Ltd. (this is the norm within the
industry and is intended to ensure information accuracy).

********************************************************************************
Marvell BSD License Option

If you received this File from Marvell, you may opt to use, redistribute and/or
modify this File under the following licensing terms.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

	* Redistributions of source code must retain the above copyright notice,
	  this list of conditions and the following disclaimer.

	* Redistributions in binary form must reproduce the above copyright
	  notice, this list of conditions and the following disclaimer in the
	  documentation and/or other materials provided with the distribution.

	* Neither the name of Marvell nor the names of its contributors may be
	  used to endorse or promote products derived from this software without
	  specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*******************************************************************************/

#ifndef _DDR3_A38X_H
#define _DDR3_A38X_H

#define MAX_INTERFACE_NUM		1
#define MAX_BUS_NUM			5
#define DDR_IF_CTRL_SUBPHYS_NUM		3

#define DFS_LOW_FREQ_VALUE		120

#include "ddr3_hws_hw_training_def.h"

#define ECC_SUPPORT

/* right now, we're not supporting this in mainline */
#undef SUPPORT_STATIC_DUNIT_CONFIG

/* Controler bus divider 1 for 32 bit, 2 for 64 bit */
#define DDR_CONTROLLER_BUS_WIDTH_MULTIPLIER	1

/* Tune internal training params values */
#define TUNE_TRAINING_PARAMS_CK_DELAY		160
#define TUNE_TRAINING_PARAMS_PHYREG3VAL		0xA
#define TUNE_TRAINING_PARAMS_PRI_DATA		123
#define TUNE_TRAINING_PARAMS_NRI_DATA		123
#define TUNE_TRAINING_PARAMS_PRI_CTRL		74
#define TUNE_TRAINING_PARAMS_NRI_CTRL		74
#define TUNE_TRAINING_PARAMS_P_ODT_DATA		45
#define TUNE_TRAINING_PARAMS_N_ODT_DATA		45
#define TUNE_TRAINING_PARAMS_P_ODT_CTRL		45
#define TUNE_TRAINING_PARAMS_N_ODT_CTRL		45
#define TUNE_TRAINING_PARAMS_DIC		0x2
#define TUNE_TRAINING_PARAMS_ODT_CONFIG_2CS	0x120012
#define TUNE_TRAINING_PARAMS_ODT_CONFIG_1CS	0x10000
#define TUNE_TRAINING_PARAMS_RTT_NOM		0x44
#define TUNE_TRAINING_PARAMS_RTT_WR_1CS		0x0
#define TUNE_TRAINING_PARAMS_RTT_WR_2CS		0x0

#if defined(CONFIG_DDR4)
#define TUNE_TRAINING_PARAMS_P_ODT_DATA_DDR4	0xD
#define TUNE_TRAINING_PARAMS_DIC_DDR4		0x0
#define TUNE_TRAINING_PARAMS_ODT_CONFIG_DDR4	0x330012
#define TUNE_TRAINING_PARAMS_RTT_NOM_DDR4	0x400 /*RZQ/3 = 0x600*/
#define TUNE_TRAINING_PARAMS_RTT_WR		0x200 /*RZQ/1 = 0x400*/
#else /* CONFIG_DDR4 */
#define TUNE_TRAINING_PARAMS_RTT_WR		0x0   /*off*/
#endif /* CONFIG_DDR4 */

#define MARVELL_BOARD				MARVELL_BOARD_ID_BASE


#define REG_DEVICE_SAR1_ADDR			0xe4204
#define RST2_CPU_DDR_CLOCK_SELECT_IN_OFFSET	17
#define RST2_CPU_DDR_CLOCK_SELECT_IN_MASK	0x1f
#define DEVICE_SAMPLE_AT_RESET2_REG		0x18604

#define DEVICE_SAMPLE_AT_RESET2_REG_REFCLK_OFFSET	0
#define DEVICE_SAMPLE_AT_RESET2_REG_REFCLK_25MHZ	0
#define DEVICE_SAMPLE_AT_RESET2_REG_REFCLK_40MHZ	1

/* DRAM Windows */
#define REG_XBAR_WIN_5_CTRL_ADDR		0x20050
#define REG_XBAR_WIN_5_BASE_ADDR		0x20054

/* DRAM Windows */
#define REG_XBAR_WIN_4_CTRL_ADDR                0x20040
#define REG_XBAR_WIN_4_BASE_ADDR                0x20044
#define REG_XBAR_WIN_4_REMAP_ADDR               0x20048
#define REG_XBAR_WIN_7_REMAP_ADDR               0x20078
#define REG_XBAR_WIN_16_CTRL_ADDR               0x200d0
#define REG_XBAR_WIN_16_BASE_ADDR               0x200d4
#define REG_XBAR_WIN_16_REMAP_ADDR              0x200dc
#define REG_XBAR_WIN_19_CTRL_ADDR               0x200e8

#define REG_FASTPATH_WIN_BASE_ADDR(win)         (0x20180 + (0x8 * win))
#define REG_FASTPATH_WIN_CTRL_ADDR(win)         (0x20184 + (0x8 * win))

/* SatR defined too change topology busWidth and ECC configuration */
#define DDR_SATR_CONFIG_MASK_WIDTH		0x8
#define DDR_SATR_CONFIG_MASK_ECC		0x10
#define DDR_SATR_CONFIG_MASK_ECC_PUP		0x20

#define	REG_SAMPLE_RESET_HIGH_ADDR		0x18600

#define MV_BOARD_REFCLK				MV_BOARD_REFCLK_25MHZ

/* Matrix enables DRAM modes (bus width/ECC) per boardId */
#define TOPOLOGY_UPDATE_32BIT			0
#define TOPOLOGY_UPDATE_32BIT_ECC		1
#define TOPOLOGY_UPDATE_16BIT			2
#define TOPOLOGY_UPDATE_16BIT_ECC		3
#define TOPOLOGY_UPDATE_16BIT_ECC_PUP3		4
#define TOPOLOGY_UPDATE { \
		/* 32Bit, 32bit ECC, 16bit, 16bit ECC PUP4, 16bit ECC PUP3 */ \
		{1, 1, 1, 1, 1},	/* RD_NAS_68XX_ID */ \
		{1, 1, 1, 1, 1},	/* DB_68XX_ID	  */ \
		{1, 0, 1, 0, 1},	/* RD_AP_68XX_ID  */ \
		{1, 0, 1, 0, 1},	/* DB_AP_68XX_ID  */ \
		{1, 0, 1, 0, 1},	/* DB_GP_68XX_ID  */ \
		{0, 0, 1, 1, 0},	/* DB_BP_6821_ID  */ \
		{1, 1, 1, 1, 1}		/* DB_AMC_6820_ID */ \
	};

enum {
	CPU_1066MHZ_DDR_400MHZ,
	CPU_RESERVED_DDR_RESERVED0,
	CPU_667MHZ_DDR_667MHZ,
	CPU_800MHZ_DDR_800MHZ,
	CPU_RESERVED_DDR_RESERVED1,
	CPU_RESERVED_DDR_RESERVED2,
	CPU_RESERVED_DDR_RESERVED3,
	LAST_FREQ
};

/* struct used for DLB configuration array */
struct dlb_config {
	u32 reg_addr;
	u32 reg_data;
};

#define ACTIVE_INTERFACE_MASK			0x1

extern u16 a38x_odt_slope[];
extern u16 a38x_odt_intercept[];

int mv_ddr_pre_training_soc_config(const char *ddr_type);
int mv_ddr_post_training_soc_config(const char *ddr_type);

#endif /* _DDR3_A38X_H */