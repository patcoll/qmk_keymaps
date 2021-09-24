default: | keymaps qmk-clean

.PHONY: qmk
qmk: qmk_firmware/Makefile
qmk_firmware/Makefile:
	init-qmk

.PHONY: qmk-clean
qmk-clean:
	qmk clean

.PHONY: rain-vial-qmk
rain-vial-qmk: working_area/vial-qmk/Makefile
working_area/vial-qmk/Makefile:
	git clone https://github.com/rainkeebs/vial-qmk working_area/vial-qmk

.PHONY: plop-default
plop-default: qmk_firmware/keyboards/plop/keymaps/default/keymap.c
qmk_firmware/keyboards/plop/keymaps/default/keymap.c: | qmk rain-vial-qmk
	mkdir -p qmk_firmware/keyboards/plop
	rsync -avz working_area/vial-qmk/keyboards/plop/ qmk_firmware/keyboards/plop/

.PHONY: keymaps
keymaps: qmk_firmware/keyboards/plop/keymaps/patcoll/keymap.c
qmk_firmware/keyboards/plop/keymaps/patcoll/keymap.c: | qmk plop-default userspace
	init-keymaps

.PHONY: userspace
userspace: qmk_firmware/users/patcoll/patcoll.h
qmk_firmware/users/patcoll/patcoll.h: qmk
	init-userspace

.PHONY: clean
clean:
	rm -rf qmk_firmware working_area
	mkdir -p working_area
