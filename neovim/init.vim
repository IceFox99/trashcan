" Before loading this init.vim, you have to first install vim-plugin
" After install these plugins, you have to:
" 0) Install nerdfonts and select one
" 1) Install npm, yarn and clangd on your machine, 
" 	 then CocInstall coc-tsserver && CocInstall coc-clangd

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
" Plug 'karb94/neoscroll.nvim'
Plug 'mhinz/vim-startify', {'branch': 'center'}
Plug 'catppuccin/nvim', { 'as': 'catppuccin' }
Plug 'iamcco/markdown-preview.nvim', { 'do': 'cd app && yarn install' }
Plug 'francoiscabrol/ranger.vim'
Plug 'rbgrouleff/bclose.vim'
Plug 'mkitt/tabline.vim'
Plug 'p00f/godbolt.nvim'
call plug#end()

" <leader> key
let g:mapleader=" "

" no swap file
set noswapfile

" ranger.nvim
let g:ranger_map_keys = 0
nnoremap <silent> <C-j> :Ranger<CR>

" NERDTree
"nnoremap <silent> <C-j> :NERDTreeFocus<CR>
let g:NERDTreeMinimalUI = 1
let g:NERDTreeWinSize = 30
let g:NERDTreeShowHidden = 1
let g:NERDTreeWinPos = "left"

" colorscheme
colorscheme gruvbox
highlight Normal guibg=none ctermbg=none
highlight NonText guibg=none ctermbg=none
highlight VertSplit guibg=none ctermbg=none 
highlight MsgSeparator guibg=none ctermbg=none
highlight StatusLine cterm=none ctermbg=none

" vim split bar
set fillchars+=vert:\ 

" hide vim mode
set noshowmode

" tab settings
highlight TabLineFill guibg=none ctermbg=none

" hide statusline and commandline in neovim
set cmdheight=0

" line number
nnoremap <C-l> 80\|
set number relativenumber

" colorcolumn
"set colorcolumn=81
highlight ColorColumn ctermbg=240
autocmd FileType c,cpp,javascript,python call matchadd('ColorColumn', '\%81v', 100)

" set cursor always at center
set scrolloff=999

" hide the tilde symbol for empty
set fillchars+=eob:\ 

" FZF
let $FZF_DEFAULT_COMMAND = "find -L ~ -not -path \"*.cache*\" -not -path \"\/mnt*\""
let $FZF_DEFAULT_OPTS = '--color=gutter:-1 --preview "less {}"' 
nnoremap <silent> <leader>f :FZF<CR>

" ctags
set tags=./tags,tags;$HOME
set tags+=./TAGS,TAGS;$HOME

" markdown-preview.nvim
nnoremap <silent> <C-s> <Plug>MarkdownPreview

" switch .cpp and .h
nnoremap <silent> <A-o> :e %:p:s,.h$,.X123X,:s,.cpp$,.h,:s,.X123X$,.cpp,<CR>

" tab shortcuts
nnoremap <silent> <A-,> :tabprevious<CR>
nnoremap <silent> <A-.> :tabnext<CR>
nnoremap <silent> <C-n> :tabnew \| :vsplit \| :only \| call BuildEmptyPane()<CR>
nnoremap <silent> <C-m> :tabclose<CR>

" indent size
set tabstop=4
set shiftwidth=4

" wrap word
"set nowrap linebreak

" vim-airline
let g:airline#extensions#ions#tabline#enabled = 1
let g:airline#extensions#branch#enabled = 1
let g:airline_powerline_fonts = 1
let g:airline_theme = "minimalist"
let g:airline#extensions#whitespace#enabled = 0
let g:airline#extensions#wordcount#enabled = 0
set laststatus=3

" coc.nvim
inoremap <expr> <cr> coc#pum#visible() ? coc#pum#confirm() : "\<CR>"
inoremap <expr> <Tab> coc#pum#visible() ? coc#pum#next(1) : "\<Tab>"
inoremap <expr> <S-Tab> coc#pum#visible() ? coc#pum#prev(1) : "\<S-Tab>"
highlight SignColumn guibg=none ctermbg=none

" neoscroll.nvim
"lua require('neoscroll').setup()

" vim-startify
let g:startify_center = 100

" WSL yank support, COMMENT them if not on WSL!!
let s:clip = '/mnt/c/Windows/System32/clip.exe'  " change this path according to your mount point
if executable(s:clip)
    augroup WSLYank
        autocmd!
        autocmd TextYankPost * if v:event.operator ==# 'y' | call system(s:clip, @0) | endif
    augroup END
endif

" Godbolt shortcuts
nnoremap <silent> <F9> :only \| :Godbolt<CR> \| <CR>

" empty left pane
let g:empty_pane_width = &columns / 4
let g:mode_switcher = 1
function! BuildEmptyPane()
	if g:mode_switcher && &columns == getenv('terminal_width')
		execute "silent leftabove " . g:empty_pane_width . " vsplit new"
		setlocal noma
		setlocal nocursorline
		setlocal nonumber
		silent! setlocal norelativenumber
		wincmd l
	endif
endfunction
autocmd VimEnter * call BuildEmptyPane()
autocmd TabNew * call BuildEmptyPane()
nnoremap <silent> <F5> :let g:mode_switcher=1 \| :vsplit \| :wincmd p \| :only \| call BuildEmptyPane()<CR>
nnoremap <silent> <F6> :let g:mode_switcher=0 \| :vsplit \| :wincmd p \| :only<CR>
