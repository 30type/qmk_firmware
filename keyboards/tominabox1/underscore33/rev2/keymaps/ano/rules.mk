
# Enable common features
COMBO_ENABLE 		   = yes
MOUSEKEY_ENABLE        = yes
CAPS_WORD_ENABLE       = yes
LEADER_ENABLE          = yes
LTO_ENABLE             = yes

# Disable unused features
MAGIC_ENABLE	       = yes
CONSOLE_ENABLE         = no
BOOTMAGIC_ENABLE       = no
UNICODE_ENABLE         = no
SPACE_CADET_ENABLE     = no
GRAVE_ESC_ENABLE       = no
AUDIO_ENABLE 	       = no

# Add custom features
SRC += features/nshot_mod.c
INTROSPECTION_KEYMAP_C = nshot.c
