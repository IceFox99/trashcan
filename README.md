# Sand

This is a mini language called ***Sand*** with ll(1) parser and a simple interpreter, it supports explicit function inling, function redefinition, labeled loop, etc. Its grammar is c-style, you can look at this [example](examples/test.sand) code written in sand.

## How to run
`g++` and `make` are required.

```bash
git clone https://github.com/IceFox99/Trashcan.git
cd Trashcan && git checkout Sand && make
cd bin && ./sand # add a file as a argument if you want to interpret it, otherwise it will run into runtime environment
```
