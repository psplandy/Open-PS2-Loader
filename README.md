# Open PS2 Loader

Copyright 2013, Ifcaro & jimmikaelkael
Licensed under Academic Free License version 3.0
Review the LICENSE file for further details.

[![CI](https://github.com/ifcaro/Open-PS2-Loader/workflows/CI/badge.svg)](https://github.com/ifcaro/Open-PS2-Loader/actions?query=workflow%3ACI)
[![Discord](https://img.shields.io/discord/652861436992946216?style=flat&logo=Discord)](https://discord.gg/CVFUa9xh6B)
[![Mega](https://img.shields.io/badge/Mega-%23D90007.svg?style=flat&logo=Mega&logoColor=white)](https://mega.nz/folder/Ndwi1bAK#oLWNhH_g-h0p4BoT4c556A)

## Introduction

Open PS2 Loader (OPL) is a 100% Open source game and application loader for
the PS2 and PS3 units. It supports three categories of devices: USB mass
storage devices, SMB shares and the PlayStation 2 HDD unit. USB devices and
SMB shares support USBExtreme and \*.ISO formats while PS2 HDD supports HDLoader
format. It's now the most compatible homebrew loader.

OPL is also developed continuously - anyone can contribute improvements to
the project due to its open-source nature.

You can visit the Open PS2 Loader forum at:

<https://www.psx-place.com/forums/open-ps2-loader-opl.77/>

You can report compatibility game problems at:

<https://www.psx-place.com/threads/open-ps2-loader-game-bug-reports.19401/>

For an updated compatibility list, you can visit the OPL-CL site at:

<http://sx.sytes.net/oplcl/games.aspx>

<details>
  <summary> <b> Release types </b> </summary>
<p>

Open PS2 Loader bundle included several types of the same OPL version. These
types come with more or fewer features included.

| Type (can be a combination) | Description                                                                             |
| --------------------------- | --------------------------------------------------------------------------------------- |
| `Release`                   | Regular OPL release with GSM, IGS, PADEMU, VMC, PS2RD Cheat Engine & Parental Controls. |
| `DTL_T10000`                | OPL for TOOLs (DevKit PS2)                                                              |
| `IGS`                       | OPL with InGame Screenshot feature.                                                     |
| `PADEMU`                    | OPL with Pad Emulation for DS3 & DS4.                                                   |
| `RTL`                       | OPL with the right to left language support.                                            |

</p>
</details>

<details>
  <summary> <b> How to use </b> </summary>
<p>

OPL uses the following directory tree structure across HDD, SMB, and
USB modes:

| Folder | Description                                          | Modes       |
| ------ | ---------------------------------------------------- | ----------- |
| `CD`   | for games on CD media - i.e. blue-bottom discs       | USB and SMB |
| `DVD`  | for DVD5 and DVD9 images if using the NTFS file system on USB or SMB; DVD9 images must be split and placed into the device root if using the FAT32 file system on USB or SMB | USB and SMB |
| `VMC`  | for Virtual Memory Card images - from 8MB up to 64MB | all         |
| `CFG`  | for saving per-game configuration files              | all         |
| `ART`  | for game art images                                  | all         |
| `THM`  | for themes support                                   | all         |
| `LNG`  | for translation support                              | all         |
| `CHT`  | for cheats files                                     | all         |

OPL will automatically create the above directory structure the first time you launch it and enable your favorite device.

For HDD users, OPL will read hdd0:\_\_common/OPL/conf_hdd.cfg for the config entry "hdd_partition" to use as your OPL partition.
If not found a config file and a 128Mb +OPL partition will be created. You can edit the config if you wish to use/create a different partition.
All partitions created by OPL will be 128Mb (it is not recommended to enlarge partitions as it will break LBAs, instead remove and recreate manually with uLaunchELF at a larger size if needed).

</p>
</details>

<details>
  <summary> <b> USB </b> </summary>
<p>

Game files on USB must be perfectly defragmented either file by file or
by whole drive, and Dual Layer DVD9 images must be split to avoid the 4GB
limitations of the FAT32 file system. We do not recommend using any programs.
The best way for defragmenting - copy all files to pc, format USB, copy all files back.
Repeat it once you faced defragmenting problem again.

You also need a PC program to convert or split games into USB Advance/Extreme
format, such as USBUtil 2.0.

</p>
</details>

<details>
  <summary> <b> SMB </b> </summary>
<p>

For loading games by SMB protocol, you need to share a folder (ex: PS2SMB)
on the host machine or NAS device and make sure that it has full read and
write permissions. USB Advance/Extreme format is optional - \*.ISO images
are supported using the folder structure above with the bonus that
DVD9 images don't have to be split if your SMB device uses the NTFS or
EXT3/4 file system.

</p>
</details>

<details>
  <summary> <b> HDD </b> </summary>
<p>

For PS2, 48-bit LBA internal HDDs up to 2TB are supported. They have to be
formatted with either HDLoader or uLaunchELF (uLaunchELF is recommended).

To launch OPL, you can use any of the existing methods for loading an
executable elf.

</p>
</details>

<details>
  <summary> <b> PS3 </b> </summary>
<p>

On PS3, you need an original SwapMagic 3.6+ or 3.8 disc (at the moment
there aren't any other options). The steps for loading OPL on a PS3 are:

1.  Rename OPNPS2LD.ELF to SMBOOT0.ELF
2.  Make a folder in the root of a USB device called SWAPMAGIC and copy SMBOOT0.ELF to it.
3.  Launch SwapMagic in PS3 and press UP+L1 then Open PS2 Loader should start.

There are 4 forms for launching elfs in SwapMagic.

SMBOOT0.ELF = UP + L1
SMBOOT1.ELF = UP + L2
SMBOOT2.ELF = UP + R1
SMBOOT3.ELF = UP + R2

Note: on PS3, only USB and SMB modes are supported.

</p>
</details>

<details>
  <summary> <b> Some notes for DEVS </b> </summary>
<p>

Open PS2 Loader needs the [**latest PS2SDK**](https://github.com/ps2dev/ps2sdk)

</p>
</details>

<details>
  <summary> <b> OPL Archive </b> </summary>
<p>

Since 05/07/2021 every OPL build dispatched to the release section of this repository will be uploaded to a mega account, you can access the archive by clicking the mega badge on top of this readme

</p>
</details>
