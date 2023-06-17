" Before loading this init.vim, you have to first install vim-plugin
" After install these plugins, you have to:
" 0) Install nerdfonts and select one
" 1) Install npm and clangd on your machine, 
" 	 then CocInstall coc-tsserver && CocInstall clangd
" 	 1.5) If you're on WSL2, you have to modify
" 	 	  ~/.config/nvim/coc-settings.json, set 
"		  \"clangd.path":"your/path/to/clangd"

call plug#begin('~/.config/nvim/plugged')
Plug 'preservim/nerdtree'
Plug 'folke/tokyonight.nvim'
Plug 'morhetz/gruvbox'
Plug 'jiangmiao/auto-pairs'
Plug 'junegunn/fzf', { 'do': { -> fzf#install() } }
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'tpope/vim-fugitive'
Plug 'neoclide/coc.nvim', {'branch': 'release'}
Plug 'ryanoasis/vim-devicons'
Plug 'karb94/neoscroll.nvim'
Plug 'mhinz/vim-startify', {'branch': 'center'}
Plug 'catppuccin/nvim', { 'as': 'catppuccin' }
call plug#end()

" <leader> key
let g:mapleader=" "

" NERDTree
nnoremap <silent> <C-j> :NERDTreeFocus<CR>
let g:NERDTreeMinimalUI = 1
let g:NERDTreeWinSize = 20
let g:NERDTreeShowHidden = 1
let g:NERDTreeWinPos = "left"

" colorscheme
colorscheme gruvbox
highlight Normal guibg=none
highlight NonText guibg=none
highlight Normal ctermbg=none
highlight NonText ctermbg=none

" line number
set number

" FZF
let $FZF_DEFAULT_COMMAND = "find -L ~ -not -path \"*.cache*\""
let $FZF_DEFAULT_OPTS = '--preview "less {}"'
nnoremap <silent> <leader>f :FZF<CR>

" switch .cpp and .h
nnoremap <silent> <leader>o :e %:p:s,.h$,.X123X,:s,.cpp$,.h,:s,.X123X$,.cpp,<CR>

" indent size
set tabstop=4
set shiftwidth=4

" wrap word
set nowrap

" vim-airline
let g:airline#extensions#ions#tabline#enabled = 1
let g:airline#extensions#branch#enabled = 1
let g:airline_powerline_fonts = 1
let g:airline_theme="minimalist"

" coc.nvim
inoremap <expr> <cr> coc#pum#visible() ? coc#pum#confirm() : "\<CR>"
inoremap <expr> <Tab> coc#pum#visible() ? coc#pum#next(1) : "\<Tab>"
inoremap <expr> <S-Tab> coc#pum#visible() ? coc#pum#prev(1) : "\<S-Tab>"

" neoscroll.nvim
lua require('neoscroll').setup()

" vim-startify
let g:startify_center = 40

" WSL yank support, COMMENT them if not on WSL!!
let s:clip = '/mnt/c/Windows/System32/clip.exe'  " change this path according to your mount point
if executable(s:clip)
    augroup WSLYank
        autocmd!
        autocmd TextYankPost * if v:event.operator ==# 'y' | call system(s:clip, @0) | endif
    augroup END
endif
