/*
 *  drivers/mtd/nand_ecc.h
 *
 *  Copyright (C) 2000 Steven J. Hill (sjhill@realitydiluted.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This file is the header for the ECC algorithm.
 */

#ifndef __MTD_NAND_ECC_H__
#define __MTD_NAND_ECC_H__

struct mtd_info;

/*
 * Calculate 3 byte ECC code for 256 byte block
 */
int nand_calculate_ecc(struct mtd_info *mtd, const u_char *dat, u_char *ecc_code);

/*
 * Detect and correct a 1 bit error for 256 byte block
 */
int nand_correct_data(struct mtd_info *mtd, u_char *dat, u_char *read_ecc, u_char *calc_ecc);

#ifdef CONFIG_NAND_ECC_SOFT_RS
/*
 * Calculate 10 byte RS ECC syndrome for 512 byte block
 */
int nand_rs_calculate_ecc(struct mtd_info *mtd, const uint8_t *data, uint8_t *ecc);
#endif

#endif /* __MTD_NAND_ECC_H__ */
