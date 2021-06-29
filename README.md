# my qmk keymaps

I got tired of maintaining my own fork of the QMK firmware repository. The work
wasn't worth it, especially when maintaining my own bilateral combinations
fork.

The code here scripts the setup of a QMK firmware repo, symlinking my custom
keymaps, and allowing me to have a QMK working area without all the extra
maintenance.

It assumes you have `direnv`, `git`, `qmk` (The QMK CLI), and probably more.

## quick setup

Run:

- `init-qmk` to set up the default qmk repo, then
- `init-keymaps` to symlink the keymaps

Then you may run `qmk compile` and `qmk flash` commands like normal. For example:

    qmk flash -kb ut472 -km patcoll

## get more custom

To flash your custom keymaps using a custom QMK fork or something, wipe out the
`qmk_firmware` folder, clone a replacement yourself, then initialize the
keymaps. Then you should be able to flash using that custom fork.
