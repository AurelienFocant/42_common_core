let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/common_core_19/cpp/cpp05/ex02
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +28 main.cpp
badd +1 abstractForms
badd +1 Classes/Forms/ShrubberyCreationForm.hpp
badd +17 Classes/Forms/ShrubberyCreationForm.cpp
badd +1 Classes/Forms/RobotomyRequestForm.cpp
badd +3 Classes/Forms/RobotomyRequestForm.hpp
badd +1 Classes/Forms/PresidentialPardonForm.hpp
badd +1 Classes/Forms/PresidentialPardonForm.cpp
badd +1 Classes/Forms/AForm.hpp
badd +31 Classes/Forms/AForm.cpp
badd +89 Classes/Bureaucrat.cpp
badd +1 Classes/Bureaucrat.hpp
argglobal
%argdel
set stal=2
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabrewind
edit Classes/Forms/AForm.hpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
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
exe 'vert 1resize ' . ((&columns * 54 + 69) / 138)
exe 'vert 2resize ' . ((&columns * 83 + 69) / 138)
argglobal
balt Classes/Forms/ShrubberyCreationForm.cpp
setlocal foldmethod=syntax
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=1
setlocal foldminlines=1
setlocal foldnestmax=2
setlocal foldenable
let s:l = 56 - ((55 * winheight(0) + 31) / 62)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 56
normal! 01|
wincmd w
argglobal
if bufexists(fnamemodify("Classes/Forms/AForm.cpp", ":p")) | buffer Classes/Forms/AForm.cpp | else | edit Classes/Forms/AForm.cpp | endif
if &buftype ==# 'terminal'
  silent file Classes/Forms/AForm.cpp
endif
balt Classes/Bureaucrat.cpp
setlocal foldmethod=syntax
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=1
setlocal foldenable
12
normal! zo
22
normal! zo
36
normal! zo
66
normal! zo
71
normal! zo
101
normal! zo
112
normal! zo
let s:l = 118 - ((64 * winheight(0) + 31) / 62)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 118
normal! 021|
wincmd w
exe 'vert 1resize ' . ((&columns * 54 + 69) / 138)
exe 'vert 2resize ' . ((&columns * 83 + 69) / 138)
tabnext
edit Classes/Forms/ShrubberyCreationForm.hpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
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
exe 'vert 1resize ' . ((&columns * 68 + 69) / 138)
exe 'vert 2resize ' . ((&columns * 69 + 69) / 138)
argglobal
balt Classes/Forms/ShrubberyCreationForm.cpp
setlocal foldmethod=syntax
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=1
setlocal foldenable
9
normal! zo
let s:l = 26 - ((24 * winheight(0) + 31) / 62)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 26
normal! 049|
wincmd w
argglobal
if bufexists(fnamemodify("Classes/Forms/ShrubberyCreationForm.cpp", ":p")) | buffer Classes/Forms/ShrubberyCreationForm.cpp | else | edit Classes/Forms/ShrubberyCreationForm.cpp | endif
if &buftype ==# 'terminal'
  silent file Classes/Forms/ShrubberyCreationForm.cpp
endif
balt Classes/Forms/AForm.hpp
setlocal foldmethod=syntax
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=1
setlocal foldenable
12
normal! zo
18
normal! zo
24
normal! zo
28
normal! zo
86
normal! zo
let s:l = 88 - ((87 * winheight(0) + 31) / 62)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 88
normal! 048|
wincmd w
exe 'vert 1resize ' . ((&columns * 68 + 69) / 138)
exe 'vert 2resize ' . ((&columns * 69 + 69) / 138)
tabnext
edit Classes/Forms/RobotomyRequestForm.hpp
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
exe 'vert 1resize ' . ((&columns * 25 + 69) / 138)
exe 'vert 2resize ' . ((&columns * 56 + 69) / 138)
exe 'vert 3resize ' . ((&columns * 55 + 69) / 138)
argglobal
enew
file NvimTree_3
balt Classes/Forms/RobotomyRequestForm.hpp
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=1
setlocal nofoldenable
wincmd w
argglobal
balt Classes/Forms/RobotomyRequestForm.cpp
setlocal foldmethod=syntax
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=1
setlocal foldenable
let s:l = 3 - ((2 * winheight(0) + 31) / 62)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 3
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("Classes/Forms/RobotomyRequestForm.cpp", ":p")) | buffer Classes/Forms/RobotomyRequestForm.cpp | else | edit Classes/Forms/RobotomyRequestForm.cpp | endif
if &buftype ==# 'terminal'
  silent file Classes/Forms/RobotomyRequestForm.cpp
endif
balt Classes/Forms/RobotomyRequestForm.hpp
setlocal foldmethod=syntax
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=1
setlocal foldenable
6
normal! zo
10
normal! zo
15
normal! zo
22
normal! zo
let s:l = 23 - ((21 * winheight(0) + 31) / 62)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 23
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 25 + 69) / 138)
exe 'vert 2resize ' . ((&columns * 56 + 69) / 138)
exe 'vert 3resize ' . ((&columns * 55 + 69) / 138)
tabnext
edit Classes/Forms/PresidentialPardonForm.hpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
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
exe 'vert 1resize ' . ((&columns * 29 + 69) / 138)
exe 'vert 2resize ' . ((&columns * 108 + 69) / 138)
argglobal
balt Classes/Forms/PresidentialPardonForm.cpp
setlocal foldmethod=syntax
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=1
setlocal foldenable
let s:l = 1 - ((0 * winheight(0) + 31) / 62)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("Classes/Forms/PresidentialPardonForm.cpp", ":p")) | buffer Classes/Forms/PresidentialPardonForm.cpp | else | edit Classes/Forms/PresidentialPardonForm.cpp | endif
if &buftype ==# 'terminal'
  silent file Classes/Forms/PresidentialPardonForm.cpp
endif
balt Classes/Forms/PresidentialPardonForm.hpp
setlocal foldmethod=syntax
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=1
setlocal foldenable
7
normal! zo
12
normal! zo
16
normal! zo
23
normal! zo
let s:l = 24 - ((22 * winheight(0) + 31) / 62)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 24
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 29 + 69) / 138)
exe 'vert 2resize ' . ((&columns * 108 + 69) / 138)
tabnext
edit Classes/Bureaucrat.hpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
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
exe 'vert 1resize ' . ((&columns * 69 + 69) / 138)
exe 'vert 2resize ' . ((&columns * 68 + 69) / 138)
argglobal
balt Classes/Bureaucrat.cpp
setlocal foldmethod=syntax
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=3
setlocal foldminlines=1
setlocal foldnestmax=1
setlocal foldenable
let s:l = 20 - ((18 * winheight(0) + 31) / 62)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 20
normal! 017|
lcd ~/common_core_19/cpp/cpp05/ex02
wincmd w
argglobal
if bufexists(fnamemodify("~/common_core_19/cpp/cpp05/ex02/Classes/Bureaucrat.cpp", ":p")) | buffer ~/common_core_19/cpp/cpp05/ex02/Classes/Bureaucrat.cpp | else | edit ~/common_core_19/cpp/cpp05/ex02/Classes/Bureaucrat.cpp | endif
if &buftype ==# 'terminal'
  silent file ~/common_core_19/cpp/cpp05/ex02/Classes/Bureaucrat.cpp
endif
balt ~/common_core_19/cpp/cpp05/ex02/Classes/Forms/AForm.cpp
setlocal foldmethod=syntax
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=1
setlocal foldenable
9
normal! zo
14
normal! zo
18
normal! zo
26
normal! zo
31
normal! zo
67
normal! zo
84
normal! zo
106
normal! zo
111
normal! zo
116
normal! zo
let s:l = 40 - ((39 * winheight(0) + 31) / 62)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 40
normal! 047|
lcd ~/common_core_19/cpp/cpp05/ex02
wincmd w
exe 'vert 1resize ' . ((&columns * 69 + 69) / 138)
exe 'vert 2resize ' . ((&columns * 68 + 69) / 138)
tabnext
edit ~/common_core_19/cpp/cpp05/ex02/Classes/Bureaucrat.cpp
argglobal
balt ~/common_core_19/cpp/cpp05/ex02/main.cpp
setlocal foldmethod=syntax
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=1
setlocal foldenable
84
normal! zo
let s:l = 89 - ((88 * winheight(0) + 31) / 62)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 89
normal! 045|
tabnext 5
set stal=1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
