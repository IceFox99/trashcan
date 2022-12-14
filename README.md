# Gojuon
A simple practice of speaking or writing Gojūon (50 Japanese syllables)

- [Writing Test](src/Test.cpp?plain=1#L19-L47): With given romaji, write the corresponding hiragana and katakana on a paper or whatever you like.
- [Reading Test](src/Test.cpp?plain=1#L49-L80): With given hiragana, katakana, dakuon or yoon, read it as soon as possible.
- [Hiragana Reading Test](src/Test.cpp?plain=1#L82-L112): With given hiragana, read it as soon as possible.
- [Katakana Reading Test](src/Test.cpp?plain=1#L114-L144): With given katakana, read it as soon as possible.
- [Dakuon Reading Test](src/Test.cpp?plain=1#L146-L180): With given dakuon, read it as soon as possible.
- [Yoon Reading Test](src/Test.cpp?plain=1#L182-L217): With given yoon, read it as soon as possible.
- [Gojuon Charts](src/Test.cpp?plain=1#L219-L236): Show all Gojuon charts.

## Getting Started
We only support *Windows* and *Linux* at present. In *Windows*, Gojuon is only officially tested on *Visual Studio 2019* and *2022*, we recommend downloading *Visual Studio* if you are using *Windows*. Or you could just download the [Windows installer](https://github.com/IceFox99/Gojuon/releases) (x64 only) in the *Release* page.

### Windows 
1. Open the cmd (or any other shell), start by cloning the repository with `git clone https://github.com/IceFox99/Gojuon.git`.
2. Go to the *Gojuon* folder in cmd, input `mkdir build && cd build && cmake ..` to build this project.
3. Open the *Gojuon.sln* file in the *build* directory with Visual Studio.
4. Hit `F5` to run this program.
5. (Optional) Right click the cmd icon and choose *properties*, adjust the font to the appropriate size.

### Linux && MacOS
1. Open the terminal, start by cloning the repository with `git clone https://github.com/IceFox99/Gojuon.git`.
2. Go to the *Gojuon* folder in terminal, input `mkdir build && cd build && cmake .. && make` to build this project.
3. Input `./Gojuon` in the *build* directory every time you want to run this program.
4. (Optional) Adjust the font to the appropriate size in your terminal.
