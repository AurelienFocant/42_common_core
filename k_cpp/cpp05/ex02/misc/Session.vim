let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/common_core/k_cpp/cpp05/ex02
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +87 Classes/Bureaucrat.cpp
badd +100 Classes/Forms/AForm.cpp
badd +69 ~/common_core/k_cpp/cpp05/ex02/Classes/Forms/AForm.hpp
badd +35 Classes/Forms/PresidentialPardonForm.cpp
badd +34 Classes/Forms/RobotomyRequestForm.cpp
badd +79 Classes/Forms/ShrubberyCreationForm.cpp
badd +1 main.cpp
badd +1 term://~/common_core/k_cpp/cpp05/ex02//129241:zsh
badd +9 ~/common_core/k_cpp/cpp05/ex02/Classes/Bureaucrat.hpp
argglobal
%argdel
edit main.cpp
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
exe 'vert 1resize ' . ((&columns * 25 + 127) / 254)
exe 'vert 2resize ' . ((&columns * 114 + 127) / 254)
exe 'vert 3resize ' . ((&columns * 113 + 127) / 254)
argglobal
enew
file NvimTree_1
balt main.cpp
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=1
setlocal foldminlines=1
setlocal foldnestmax=2
setlocal nofoldenable
wincmd w
argglobal
balt Classes/Bureaucrat.cpp
setlocal foldmethod=syntax
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=2
setlocal foldminlines=1
setlocal foldnestmax=2
setlocal foldenable
15
normal! zo
40
normal! zo
40
normal! zc
64
normal! zo
64
normal! zc
89
normal! zc
let s:l = 15 - ((14 * winheight(0) + 31) / 63)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 15
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("term://~/common_core/k_cpp/cpp05/ex02//129241:zsh", ":p")) | buffer term://~/common_core/k_cpp/cpp05/ex02//129241:zsh | else | edit term://~/common_core/k_cpp/cpp05/ex02//129241:zsh | endif
if &buftype ==# 'terminal'
  silent file term://~/common_core/k_cpp/cpp05/ex02//129241:zsh
endif
balt Classes/Forms/ShrubberyCreationForm.cpp
setlocal foldmethod=syntax
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=1
setlocal foldminlines=1
setlocal foldnestmax=2
setlocal foldenable
let s:l = 63 - ((62 * winheight(0) + 31) / 63)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 63
normal! 0
wincmd w
2wincmd w
exe 'vert 1resize ' . ((&columns * 25 + 127) / 254)
exe 'vert 2resize ' . ((&columns * 114 + 127) / 254)
exe 'vert 3resize ' . ((&columns * 113 + 127) / 254)
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
