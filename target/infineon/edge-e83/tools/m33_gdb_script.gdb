target remote:3333
set mem inaccessible-by-default off
set remotetimeout 500
monitor reset_halt cm33_ns
break main
