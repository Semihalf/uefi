

# CAVIUM



**New ARM Trusted Firmware branch** 

**Introduction to thunder-dev**


Contents:

1. [Overview](#1-overview)

2. [Supported platforms](#2-supported-platforms)

3. [New baseline](#3-new-baseline)

4. [Rationale for branch transition](#4-rationale-for-branch-transition)

5. [Code structure](#5-code-structure)

6. [Multi-targets support infrastructure](#6-multi-targets-support-infrastructure)

    *   6.1 [General approach](#61-general-approach)

    *   6.2 [Code structure for different Cavium platform](#62-code-structure-for-different-cavium-platform)

7. [Development Flow](#7-development-flow)

8. [thunder-dev ATF roadmap](#8-thunder-dev-ATF-roadmap)

9. [FAQs](#9-faqs)





1. Overview
----------------

This document describes new unified ATF branch named `thunder-dev`. Its goal is to help Cavium SDK developers to make transition to new branch and introduce changes made in ATF in comparison to old `thunder-master`. It also comprises some general ARM Trusted Firmware features description, in order to shed more light on this firmware stage.

2. Supported platforms
---------------

`thunder-dev` comprises support for CN81xx (T81) and CN83xx (T83). For sake of simplicity, simplified t81 and t83 names will be used in this document.

3. New baseline
---------------
`thunder-dev` ATF branch is based on ATF version 1.2 maintained by ARM. Explicit commit revision is as below:

**[d0c104e](https://github.com/ARM-software/arm-trusted-firmware/tree/v1.2): &quot;Merge pull request #475 from danh-arm/dh/v1.2-final&quot;**

Previous `thunder-master` branch was based on v0.3 and in order to review all changes between v0.3 and v1.2 one has to view documentation placed under docs/change-log.md file. Main changes (especially from CAVIUM point of view) are mentioned in next chapter [Rationale for branch transition](#4-rationale-for-branch-transition).

4. Rationale for branch transition
---------------

Transition to `thunder-dev` codebase improves ATF stability and performance of this firmware stage. It also introduce big frameworks rework, which developers must be aware of.

* Multi-target support - described in details in 6 paragraph of this document
* Improved GICv3 support
	-  All platform specific configurations and registration of different interrupts are moved to **`plat/cavium/common/thunder_gicv3.c`** file
	- Generic GIC files are divided between GICv2 and GICv3, there is no longer support for hybrid versions
* PSCI improvement - support for v1.0 of the PSCI
* Introduction of Secure Payload and Secure Payload Dispatcher - it's framework which allows to reduce amount of code running in EL3 and move it to Secure EL1. Its usage for Cavium platforms is on the ToDo list for Firmware Team
* General code clean-up

5. Code structure
---------------

Basic ATF code structure is described in documentation under docs directory. In this paragraph only the most important (from the Cavium developer point of view) directories are described.

*   **`docs/`**
	- Comprises all ATF documentation
	- Documentation specific for Cavium SoC's will be placed under **`docs/plat/cavium/`** directory
*  **`drivers/`**
	- Comprises basic devices' drivers
	- Cavium specific devices' drivers are placed under **`drivers/cavium/`** directory
*  **`plat/`**
	- Comprises platform specific code
	- **` plat/common/`** comprises architectural initialization common for every platform
*  **` plat/cavium`**
	- Comprises common and platform specific architectural code
	- Code common for every Cavium platform is placed under **`plat/cavium/common`** directory
	- Header files common for Cavium platforms are placed under **`plat/cavium/common/include`** directory
	- There are directories for platform specific code named accordingly to platform names **`plat/cavium/t81`** and **`plat/cavium/t83`**
	- [Next paragraph](#6-multi-targets-support-infrastructure) describes in detail how multiple platforms support is handled



6. Multi-targets support infrastructure
---------------

### 6.1 General approach

One of the most important benefit of switching to _thunder-dev_ ATF branch is that it contains support for multiple targets. We can choose platform for which code will be build at compilation time. In general there are two options to distinguish between SoC version:

* At build time
	- Using different makefile helpers depending on the currently builded target
	- Introduce macros for every target and compile some code parts conditionally
* At runtime
	- Read MIDR register and decide which execution path to choose

In `thunder-dev` branch, both approaches are combined. Although second option seems to be cleaner and more generic, it isn't always possible. What's more looking at small size and fast execution requirements for ATF it is necessary to use platform recognition at build time.

In order to achieve that, T81 and T83 platforms have own macros defined at the very beginning of Makefile execution:

- **`T81`** for CN81xx targets
- **`T83`** for CN83xx targets

### 6.2 Code structure for different Cavium platform

Every platform besides using common makefile helper **`plat/cavium/common/platform.mk`** directory has its own makefile helper, which is used for including different files to compilation for different targets. They are present as **`plat/cavium/<plat_name>/platform.mk`** files.

There are plenty of functions which has different implementation depending on target platform. Declaration of such functions are placed in **`plat/cavium/common/include/thunder_common.h`** and implementations are bonded during link time from   **`plat/cavium/<plat_name>/thunder_setup_<plat_name>.c`** files.



7. Development Flow
---------------

**ATF Gatekeepers:**

* Roy Franz [roy.franz@cavium.com](mailto:roy.franz@cavium.com)
* Jonathan Zhang  [jonathan.zhang@cavium.com](mailto:jonathan.zhang@cavium.com)
* Jan Dąbroś [jan.dabros@cavium.com](mailto:jan.dabros@cavium.com)

All patches intended to be applied on `thunder-dev` ATF branch must be:

* Rebased against `thunder-dev` ToT
* Pass all Linux checkpatch utility tests
* Send to **ATF Gatekeepers**

Flow is as follow:

1. Patch must get ACK from at least one of **ATF Gatekeepers** to be considered as approved.
2. If code doesn't pass step 1. it should be fixed according to comments and next version should be send (back to step 1).
3. When approved, commit will be pushed to `thunder-dev` by one of **ATF Gatekeepers**.



8. `thunder-dev` ATF roadmap
---------------

New ATF codebase must be still improved. It's necessary to implement every software solution invented by Cavium's developers and in the same time observe improvements from ARM Trusted Firmware software Team. Short term goals of ATF development are:

* Write documentation for Cavium's ATF, such as ATF ABI and run time services/APIs
* PHY management and link management
* Port appropriate T88 ATF features (Such as SATA workarounds)
* Any work needed by T81/T83 commercialization

Long term goals:

* Upgrade to ATF v1.3
* Add support for T98 platform
* Secure boot

9. FAQs
---------------

**Q:** What platforms are currently supported by this branch?

**A:** This branch currently supports CN81xx and CN83xx platforms.



**Q:** What is the core ATF code base version? How to find out documentations

about this ATF code base version?

**A:** `thunder-dev` is based on v1.2 ARM Trusted Firmware ([d0c104e: "Merge pull request #475 from danh-arm/dh/v1.2-final"](https://github.com/ARM-software/arm-trusted-firmware/tree/v1.2)). Documentation about this revision is placed under docs/change-log.md file.



**Q:** How is the multi-targets support infrastructure (such as directory structure)

designed?

**A:** This infrastructure is based on two approach - build time and runtime differentiation. It's described in details in paragraph 6 of this document.




**Q:** How should I suggest a change to this branch?

**A:** The main improvements of new `thunder-dev` are multi-target support and huge jump (from v0.3 to v1.2) in ATF version. It brings upswing in performance, stability and scalability. More on this in [paragraph 4](#4-rationale-for-branch-transition) of this document.




**Q:** How do I know ATF roadmap? What is being worked on? What is the longer

term plan?

**A:** Short and long term goals are listed in paragraph 8 of this document.




**Q:** Who is owner of new ATF branch? How looks development flow there? What should I do in order to push my work to this branch?

**A:** Firmware Team is working on new ATF codebase and gatekeepers of `thunder-dev` are Roy Franz, Jonathan Zhang and Jan Dąbroś. More on this topic can be found in [paragraph 7](#7-development-flow) of this document.




**Q:** How to build firmware stack for T81 and T83 targets?

**A:** In parallel to ATF branch rework, there was also effort to reorganize rest of firmware stages' codebases. Currently, work to add support for UEFI on T81 is still in progress on `thunder-dev` branch in edk2 repository. In order to build u-boot firmware for T81 and T83, one has to:

* Checkout below branches on every of following repositories:
	- SDK-NEW: **`thunder-dev`**
	- BDK-RELEASES: **`master`**
	- ATF: **`thunder-dev`**
	- U-BOOT: **`thunder-dev`**
* While in SDK-NEW invoke:

_`source env-setup`_

* While in SDK-NEW repository invoke make command with PLAT variable set to proper target
	- For T81:

_`make uboot-build PLAT=t81`_

	- For T83:

_`make uboot-build PLAT=t83`_

* Image ready to burn on flash:
	- For T81

**`target/images/thunder-bootfs-uboot-t81.img`**

	- For T83
	
**`target/images/thunder-bootfs-uboot-t83.img`**

