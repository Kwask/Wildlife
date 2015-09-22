export CXX="g++"

echo "Environment: `uname -a`"
echo "Compiler: `$CXX --version`"

make || exit 1