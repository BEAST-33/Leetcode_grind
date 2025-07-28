#!/usr/bin/env python3
"""
Test runner for the Count Subsequences problem.
This script compiles and runs the C++ solution against test cases.
"""

import subprocess
import sys
import os

def compile_cpp():
    """Compile the C++ solution."""
    try:
        subprocess.run(['g++', '-std=c++17', '-O2', 'q6subseq.cpp', '-o', 'q6subseq'], 
                      check=True, capture_output=True)
        print("✓ C++ code compiled successfully")
        return True
    except subprocess.CalledProcessError as e:
        print(f"✗ Compilation failed: {e.stderr.decode()}")
        return False

def run_test_case(input_data, expected_output):
    """Run a single test case."""
    try:
        result = subprocess.run(['./q6subseq'], 
                              input=input_data.encode(), 
                              capture_output=True, 
                              text=True, 
                              timeout=5)
        
        if result.returncode != 0:
            return False, f"Runtime error: {result.stderr}"
        
        actual_output = result.stdout.strip()
        if actual_output == str(expected_output):
            return True, actual_output
        else:
            return False, f"Expected {expected_output}, got {actual_output}"
            
    except subprocess.TimeoutExpired:
        return False, "Timeout"
    except Exception as e:
        return False, f"Error: {str(e)}"

def main():
    # Test cases: (input_data, expected_output, description)
    test_cases = [
        ("1\n1", 1, "Single odd digit"),
        ("2\n1 3", 3, "Two odd digits"),
        ("2\n1 2", 3, "Odd and even digits"),
        ("2\n2 2", 3, "Two even digits"),
        ("3\n1 3 5", 7, "Three odd digits"),
        ("3\n1 2 3", 7, "Odd, even, odd"),
        ("3\n2 1 2", 7, "Even, odd, even"),
        ("4\n1 2 3 5", 15, "All digits from 1235"),
        ("4\n1 2 1 2", 15, "Alternating pattern"),
        ("4\n1 3 5 2", 15, "Three odds followed by even"),
        ("5\n1 2 3 1 2", 31, "Repeating pattern"),
        ("1\n2", 1, "Single even digit"),
        ("6\n1 2 3 5 1 2", 63, "Large array with pattern"),
        ("3\n1 1 1", 7, "All same odd number"),
        ("3\n2 2 2", 7, "All same even number"),
        ("5\n1 2 1 2 1", 31, "Mixed pattern"),
        ("4\n1 2 3 2", 15, "Pattern avoiding three consecutive"),
        ("8\n1 2 3 5 1 2 3 5", 255, "Long sequence"),
        ("10\n1 2 3 5 1 2 3 5 1 2", 1023, "Maximum constraint test"),
    ]
    
    print("Testing Count Subsequences Solution")
    print("=" * 50)
    
    # Compile the C++ code
    if not compile_cpp():
        return
    
    passed = 0
    total = len(test_cases)
    
    for i, (input_data, expected, description) in enumerate(test_cases, 1):
        print(f"\nTest {i}: {description}")
        print(f"Input: {input_data}")
        print(f"Expected: {expected}")
        
        success, result = run_test_case(input_data, expected)
        
        if success:
            print(f"✓ PASSED - Output: {result}")
            passed += 1
        else:
            print(f"✗ FAILED - {result}")
    
    print("\n" + "=" * 50)
    print(f"Results: {passed}/{total} tests passed")
    
    if passed == total:
        print("🎉 All tests passed!")
    else:
        print("❌ Some tests failed. Check the implementation.")

if __name__ == "__main__":
    main() 