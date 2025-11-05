let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/common_core/k_cpp/cpp06/ex00
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +57 Classes/ScalarConverter.cpp
badd +0 Classes/ScalarConverter.hpp
badd +0 term://~/common_core/k_cpp/cpp06/ex00//35034:zsh
argglobal
%argdel
edit Classes/ScalarConverter.cpp
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
exe 'vert 1resize ' . ((&columns * 84 + 127) / 254)
exe 'vert 2resize ' . ((&columns * 84 + 127) / 254)
exe 'vert 3resize ' . ((&columns * 84 + 127) / 254)
argglobal
balt Classes/ScalarConverter.cpp
setlocal foldmethod=syntax
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=2
setlocal foldminlines=1
setlocal foldnestmax=2
setlocal foldenable
7
normal! zc
11
normal! zc
16
normal! zo
16
normal! zc
23
normal! zc
28
normal! zo
28
normal! zc
40
normal! zc
48
normal! zc
67
normal! zc
78
normal! zc
83
normal! zo
83
normal! zc
104
normal! zc
115
normal! zo
let s:l = 116 - ((115 * winheight(0) + 31) / 63)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 116
normal! 05|
wincmd w
argglobal
if bufexists(fnamemodify("Classes/ScalarConverter.hpp", ":p")) | buffer Classes/ScalarConverter.hpp | else | edit Classes/ScalarConverter.hpp | endif
if &buftype ==# 'terminal'
  silent file Classes/ScalarConverter.hpp
endif
balt term://~/common_core/k_cpp/cpp06/ex00//35034:zsh
setlocal foldmethod=syntax
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=1
setlocal foldminlines=1
setlocal foldnestmax=2
setlocal foldenable
let s:l = 17 - ((16 * winheight(0) + 31) / 63)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 17
normal! 033|
wincmd w
argglobal
if bufexists(fnamemodify("term://~/common_core/k_cpp/cpp06/ex00//35034:zsh", ":p")) | buffer term://~/common_core/k_cpp/cpp06/ex00//35034:zsh | else | edit term://~/common_core/k_cpp/cpp06/ex00//35034:zsh | endif
if &buftype ==# 'terminal'
  silent file term://~/common_core/k_cpp/cpp06/ex00//35034:zsh
endif
balt Classes/ScalarConverter.hpp
setlocal foldmethod=syntax
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=1
setlocal foldminlines=1
setlocal foldnestmax=2
setlocal foldenable
let s:l = 49 - ((23 * winheight(0) + 31) / 63)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 49
normal! 060|
wincmd w
2wincmd w
exe 'vert 1resize ' . ((&columns * 84 + 127) / 254)
exe 'vert 2resize ' . ((&columns * 84 + 127) / 254)
exe 'vert 3resize ' . ((&columns * 84 + 127) / 254)
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
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
