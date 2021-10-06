# my qmk keymaps

I got tired of maintaining my own fork of the QMK firmware repository. So many
files that aren't mine -- it was very distracting.

Plus more and more I was building firmware for rare boards that did not have
their firmware committed to the main QMK repo. What to do?

The code in this repo contains my userspace and the custom keymaps I need to
get the most out of the boards I have. It also contains scripts to set the QMK
environment up that I need.

For local dev, it assumes you have `direnv`, `git`, `rsync`, `qmk` (The QMK
CLI), and probably more.

## quick setup

Run `make` to set everything up. Running it multiple times should do the bare
minimum to get you to a working environment. Check out the Makefile if you are
curious what it does.

Then you may run `qmk compile` and `qmk flash` commands like normal. For example:

    qmk flash -kb ut472 -km patcoll

## get more custom

If you need to use firmware from a repo that is not the main repo, set it up as
a target that checks out its files into `working_area` in the Makefile and make
the `keymaps` target depend on it.

I've found that most/all QMK forks with custom firmware can have their custom
firmware files copied into the latest version of the main QMK repo and compiled
without any issues. This way you always have the latest QMK bugfixes and
improvements and the custom firmware you need. Best of both worlds.

There are examples in the Makefile to use -- copy/paste and customize.

## test all keymaps

When editing files in the userspace, it can be useful to test your changes
across all custom keymaps.

Run the `make test` command to test building all the keymaps.
