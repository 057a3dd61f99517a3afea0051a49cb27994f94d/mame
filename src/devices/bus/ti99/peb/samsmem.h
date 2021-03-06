// license:LGPL-2.1+
// copyright-holders:Michael Zapf
/****************************************************************************

    TI-99 SuperAMS memory expansion
    See samsmem.c for documentation

    Michael Zapf
    September 2010

    February 2012: Rewritten as class

*****************************************************************************/

#ifndef MAME_BUS_TI99_PEB_SAMSMEM_H
#define MAME_BUS_TI99_PEB_SAMSMEM_H

#pragma once

#include "peribox.h"
#include "machine/ram.h"

DECLARE_DEVICE_TYPE(TI99_SAMSMEM, sams_memory_expansion_device)

class sams_memory_expansion_device : public ti_expansion_card_device
{
public:
	sams_memory_expansion_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);
	DECLARE_READ8Z_MEMBER(readz) override;
	DECLARE_WRITE8_MEMBER(write) override;

	DECLARE_READ8Z_MEMBER(crureadz) override;
	DECLARE_WRITE8_MEMBER(cruwrite) override;

	machine_config_constructor device_mconfig_additions() const override;

protected:
	void device_start() override;
	void device_reset() override;

private:
	// Console RAM
	required_device<ram_device> m_ram;
	int     m_mapper[16];
	bool    m_map_mode;
	bool    m_access_mapper;
};

#endif // MAME_BUS_TI99_PEB_SAMSMEM_H
