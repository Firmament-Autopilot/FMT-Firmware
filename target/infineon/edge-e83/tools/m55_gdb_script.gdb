target remote:3332
set mem inaccessible-by-default off
set remotetimeout 500
monitor reset_halt cm55
break main