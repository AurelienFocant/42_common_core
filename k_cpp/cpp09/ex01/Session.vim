let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/common_core/k_cpp/cpp09/ex01
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +23 RPN.hpp
badd +62 RPN.cpp
badd +0 main.cpp
argglobal
%argdel
$argadd RPN.hpp
edit RPN.cpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
2wincmd h
wincmd w
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 70 + 106) / 212)
exe 'vert 2resize ' . ((&columns * 70 + 106) / 212)
exe 'vert 3resize ' . ((&columns * 70 + 106) / 212)
argglobal
balt RPN.hpp
setlocal foldmethod=syntax
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=1
setlocal foldenable
11
sil! normal! zo
26
sil! normal! zo
let s:l = 62 - ((24 * winheight(0) + 23) / 47)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 62
normal! 013|
wincmd w
argglobal
if bufexists(fnamemodify("RPN.cpp", ":p")) | buffer RPN.cpp | else | edit RPN.cpp | endif
if &buftype ==# 'terminal'
  silent file RPN.cpp
endif
balt RPN.hpp
setlocal foldmethod=syntax
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=1
setlocal foldenable
11
sil! normal! zo
26
sil! normal! zo
let s:l = 62 - ((24 * winheight(0) + 23) / 47)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 62
normal! 025|
wincmd w
argglobal
if bufexists(fnamemodify("main.cpp", ":p")) | buffer main.cpp | else | edit main.cpp | endif
if &buftype ==# 'terminal'
  silent file main.cpp
endif
balt RPN.cpp
setlocal foldmethod=syntax
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=1
setlocal foldenable
6
sil! normal! zo
let s:l = 12 - ((11 * winheight(0) + 23) / 47)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 12
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 70 + 106) / 212)
exe 'vert 2resize ' . ((&columns * 70 + 106) / 212)
exe 'vert 3resize ' . ((&columns * 70 + 106) / 212)
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
