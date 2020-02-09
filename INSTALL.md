# Prerequisites

| Linux | macOS | Windows 10 (build 18917+) | Windows 10 (1709+) | Windows Vista, 7, 8, 8.1, and 10 (1507, 1511, 1607, and 1703)
| ----- | ----- | ------------------------- | ------------------ | ---------------------------------------------------------
| none | [Xcode Command Line Tools package][xcode] | [Windows Subsystem for Linux 2][wsl2] | [Windows Subsystem for Linux][wsl] | MSYS2 (see below)

[xcode]: https://developer.apple.com/library/archive/technotes/tn2339/_index.html#//apple_ref/doc/uid/DTS40014588-CH1-DOWNLOADING_COMMAND_LINE_TOOLS_IS_NOT_AVAILABLE_IN_XCODE_FOR_MACOS_10_9__HOW_CAN_I_INSTALL_THEM_ON_MY_MACHINE_
[wsl2]: https://docs.microsoft.com/windows/wsl/wsl2-install
[wsl]: https://docs.microsoft.com/windows/wsl/install-win10

The [prerelease version of the Linux subsystem](https://docs.microsoft.com/windows/wsl/install-legacy) available in the 1607 and 1703 releases of Windows 10 is obsolete so consider uninstalling it.

Make sure that the `build-essential`, `git`, and `libpng-dev` packages are installed. The `build-essential` package includes the `make`, `gcc-core`, and `g++` packages so they do not have to be obtained separately. MSYS2 does not include `libpng-dev` so it must be built from source.

Install the **devkitARM** toolchain of [devkitPro](https://devkitpro.org/wiki/Getting_Started) and add its environment variables. For Windows versions without the Linux subsystem, the devkitPro [graphical installer](https://github.com/devkitPro/installer/releases) includes a preconfigured MSYS2 environment, thus the steps below are not required.

	export DEVKITPRO=/opt/devkitpro
	echo "export DEVKITPRO=$DEVKITPRO" >> ~/.bashrc
	export DEVKITARM=$DEVKITPRO/devkitARM
	echo "export DEVKITARM=$DEVKITARM" >> ~/.bashrc


# Installation

To set up the repository:

	git clone https://github.com/pret/pokepinballrs
	git clone https://github.com/pret/agbcc

	cd ./agbcc
	./build.sh
	./install.sh ../pokepinballrs

	cd ../pokepinballrs
 	./build_tools.sh

Place a copy of the original ROM in the `pokepinballrs` directory, and name it `baserom.gba`. This is necessary because this is an incomplete disassembly.

To build **pokepinballrs.gba** and confirm it matches the official ROM image:

	make compare

## Notes

* If the base tools are not found on macOS in new Terminal sessions after the first successful build, run `echo "if [ -f ~/.bashrc ]; then . ~/.bashrc; fi" >> ~/.bash_profile` once to prevent the issue from occurring again. Verify that the `devkitarm-rules` package is installed as well; if not, install it by running `sudo dkp-pacman -S devkitarm-rules`.

* If the repository was previously set up using Cygwin, delete the `.exe` files in the subfolders of the `tools` folder except for `agbcc` and try building again. [Learn the differences between MSYS2 and Cygwin.](https://github.com/msys2/msys2/wiki/How-does-MSYS2-differ-from-Cygwin)

# Faster builds

After the first build, subsequent builds are faster. You can further speed up the build:

## Parallel build

This significantly speeds up the build on modern machines.

By default `make` only runs a single thread. You can tell `make` to run on multiple threads with `make -j`. See the manfile for usage (`man make`).

The optimal value for `-j` is the number of logical cores on your machine. You can run `nproc` to see the exact number.

```
$ nproc
8
```

If you have 8 cores, run: `make -j8`

`-j` on its own will spawn a new thread for each job. A clean build will have thousands of jobs, which will be slower than not using -j at all.

## Disable the dependency scanning

If you've only changed `.c` or `.s` files, you can turn off the dependency scanning temporarily. Changes to any other files will be ignored, and the build will either fail or not reflect those changes.

`make NODEP=1`


