#!/usr/bin/env python3
"""
Manual verification script for the Count Subsequences problem.
This script generates all possible subsequences and filters out invalid ones
to verify the expected output.
"""

from itertools import combinations

def is_valid_subsequence(subseq):
    """
    Check if a subsequence is valid (doesn't contain three consecutive even or odd numbers).
    """
    if len(subseq) < 3:
        return True
    
    # Check for three consecutive even numbers
    for i in range(len(subseq) - 2):
        if subseq[i] % 2 == 0 and subseq[i+1] % 2 == 0 and subseq[i+2] % 2 == 0:
            return False
    
    # Check for three consecutive odd numbers
    for i in range(len(subseq) - 2):
        if subseq[i] % 2 == 1 and subseq[i+1] % 2 == 1 and subseq[i+2] % 2 == 1:
            return False
    
    return True

def count_valid_subsequences(arr):
    """
    Count all valid non-empty subsequences.
    """
    valid_count = 0
    valid_subsequences = []
    
    # Generate all non-empty subsequences
    for length in range(1, len(arr) + 1):
        for indices in combinations(range(len(arr)), length):
            subseq = [arr[i] for i in indices]
            if is_valid_subsequence(subseq):
                valid_count += 1
                valid_subsequences.append(subseq)
    
    return valid_count, valid_subsequences

def analyze_test_case(arr, description=""):
    """
    Analyze a test case and show all valid subsequences.
    """
    print(f"\n{'='*60}")
    print(f"Test Case: {description}")
    print(f"Input array: {arr}")
    print(f"Length: {len(arr)}")
    
    count, subsequences = count_valid_subsequences(arr)
    
    print(f"\nValid subsequences ({count} total):")
    for i, subseq in enumerate(subsequences, 1):
        print(f"  {i:2d}. {subseq}")
    
    print(f"\nExpected output: {count}")
    return count

def main():
    print("Manual Verification of Count Subsequences Problem")
    print("Using digits from 1235: 1(odd), 2(even), 3(odd), 5(odd)")
    
    # Test cases using digits from 1235
    test_cases = [
        ([1], "Single odd digit"),
        ([1, 3], "Two odd digits"),
        ([1, 2], "Odd and even digits"),
        ([2, 2], "Two even digits"),
        ([1, 3, 5], "Three odd digits"),
        ([1, 2, 3], "Odd, even, odd"),
        ([2, 1, 2], "Even, odd, even"),
        ([1, 2, 3, 5], "All digits from 1235"),
        ([1, 2, 1, 2], "Alternating pattern"),
        ([1, 3, 5, 2], "Three odds followed by even"),
        ([1, 2, 3, 1, 2], "Repeating pattern"),
        ([2], "Single even digit"),
        ([1, 2, 3, 5, 1, 2], "Large array with pattern"),
        ([1, 1, 1], "All same odd number"),
        ([2, 2, 2], "All same even number"),
        ([1, 2, 1, 2, 1], "Mixed pattern"),
        ([1, 2, 3, 2], "Pattern avoiding three consecutive"),
    ]
    
    results = {}
    
    for arr, description in test_cases:
        count = analyze_test_case(arr, description)
        results[description] = count
    
    print(f"\n{'='*60}")
    print("SUMMARY OF RESULTS:")
    print("="*60)
    for description, count in results.items():
        print(f"{description:30s}: {count}")
    
    print(f"\n{'='*60}")
    print("NOTES:")
    print("- The current algorithm might not correctly handle cases with")
    print("  three consecutive even or odd numbers in the original array.")
    print("- For arrays like [1,3,5] or [2,2,2], the subsequence [1,3,5]")
    print("  or [2,2,2] should be invalid but might be counted by the algorithm.")
    print("- This verification shows the correct expected outputs.")

if __name__ == "__main__":
    main() 