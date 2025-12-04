#!/bin/bash
echo "Testing C Parser..."

echo "=== Test 1: Valid Program ==="
./c_parser < test1.c

echo ""
echo "=== Test 2: Program with Errors ==="
./c_parser < test2.c

echo ""
echo "Testing complete!"
