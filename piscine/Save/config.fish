set fish_greeting

alias fastcomp='cc -Wall -Wextra -Werror -g3 ./ft_*.c && ./a.out'
alias fastcheck='~/.script/fastcheck.sh'
alias aaa='./a.out > ex.out'
alias gitign='printf "*.out\n*.c.swo" >> .gitignore'
alias mini='~/mini-moulinette/mini-moul.sh'

python3 ~/pokemon-colorscripts/pokemon-colorscripts.py -r --no-title

if status is-interactive
    # Commands to run in interactive sessions can go here
end
