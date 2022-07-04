
if POCHA_IOE_INC eqtype 1
define POCHA_IOE_INC
include "str.inc"

define STD_INN 0
define STD_OUT 1
define STD_ERR 2

extrn num_put_str
extrn num_put_chr
extrn put
extrn put_chr
extrn put_err

end if

