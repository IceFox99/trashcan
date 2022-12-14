"=============================================================================
" init.vim --- Entry file for neovim
" Copyright (c) 2016-2022 Wang Shidong & Contributors
" Author: Wang Shidong < wsdjeg@outlook.com >
" URL: https://spacevim.org
" License: GPLv3
"=============================================================================

execute 'source' fnamemodify(expand('<sfile>'), ':h').'/main.vim'

" IceFox99's customization
let g:NERDTreeShowHidden = 1
let g:NERDTreeWinSize = 20
let g:NERDTreeWinPos = "left"
let $FZF_DEFAULT_COMMAND = "find -L ~ /usr/include/ -not -path \"*.cache*\""

nmap <silent> <C-j> :NERDTreeFocus<CR>
nmap <silent> <A-o> :e %:p:s,.hpp$,.X123X,:s,.cpp$,.hpp,:s,.X123X$,.cpp,<CR>

set tags=tags;/
set tags+=~/gcc/tags
