# pkgman
Basic tool to learn how package managers may work.

This project is also a learning test bed for C++20 (hopefully).

Because of this, it may borrow certain features of how some GNU/Linux distributions handle
their package management (`apt`, `pacman`, `yum`).

Since the plan is to make everything (that's actually possible) from scratch and
keep it as a monorepo, things may look tangled up at any point in time as the
scope of this project it not to create a clean, well organized (until I learn how to) or stable tool
but to learn those concepts with practice.

## Features
- Repository to pull packages from.
- Package description file (somethinkg like Arch's `PKGBUILD`).
- Generate package list from a binary directory.
- Query repository for available packages.
- Install a package (not system-wide) on a Linux x86_64 environment.
- TBD

