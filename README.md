# 🪄 Magic Bogosort

A revolutionary sorting algorithm that finds the **exact seed** needed to sort any array in just **one shuffle**!

## 🎯 What is Magic Bogosort?

Magic Bogosort is a deterministic sorting algorithm that:

- Finds the perfect random seed for any given array
- Sorts the array in exactly **one shuffle** using that seed
- Caches discovered seeds for instant future sorting
- Never gives up until it finds the magic seed

Unlike traditional bogosort that randomly shuffles until lucky, Magic Bogosort systematically searches for the **one specific seed** that will sort your array on the first try.

## ✨ Features

- **🎲 One-Shuffle Guarantee**: Always sorts in exactly one shuffle once the magic seed is found
- **💾 Smart Caching**: Automatically caches discovered seeds for instant re-sorting
- **🔄 Unlimited Determination**: Never gives up searching for the magic seed
- **🚀 Production Ready**: Clean, simple API with proper error handling
- **⚡ Cache Performance**: Previously sorted arrays are handled instantly

## 🚀 Quick Start

### Compilation

```bash
./compile.sh
```

The executable will be created in the `out/` directory.

### Basic Usage

```c
#include "magicbogosort.h"

int main() {
    int arr[] = {3, 1, 4, 2};
    int size = 4;

    // Sort the array and get the magic seed
    unsigned int magic_seed = magicbogosort(arr, size);

    // Array is now sorted: [1, 2, 3, 4]
    printf("Sorted using magic seed: %u\\n", magic_seed);

    return 0;
}
```

## 📚 API Reference

### Core Function

```c
unsigned int magicbogosort(int arr[], int size);
```

**Parameters:**

- `arr[]`: Array to sort (modified in-place)
- `size`: Number of elements in the array

**Returns:**

- The magic seed that was used to sort the array

**Behavior:**

- Sorts the array in-place
- Returns the seed that performed the magic
- Automatically caches the result for future use
- Never fails (keeps searching until success)

### Utility Function

```c
void print_array(int arr[], int size);
```

Prints an array in the format `[1, 2, 3, 4]` for debugging and testing.

## 🎪 How It Works

1. **Cache Check**: First checks if this array has been sorted before
2. **Direct Application**: If cached, applies the known magic seed instantly
3. **Seed Discovery**: If not cached, systematically tries seeds 0, 1, 2, 3...
4. **Magic Moment**: When a seed sorts the array in one shuffle, that's the magic seed!
5. **Auto-Cache**: Saves the magic seed for future instant sorting

## 📊 Performance

| Scenario           | Performance                       | Cache Status             |
| ------------------ | --------------------------------- | ------------------------ |
| **First Time**     | O(n × s) where s = seed discovery | Cache Miss → Discovery   |
| **Repeat Array**   | O(n)                              | Cache Hit → Instant      |
| **Similar Arrays** | O(n × s)                          | Each gets own magic seed |

## 🧪 Example Run

```bash
$ out/magicbogosort
=== Simple Magic Bogosort Test ===

Original array: [3, 1, 4, 2, 8, 5, 7, 6, 10, 9]
Sorted array with seed 3247138: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
```

## 📁 Project Structure

```
magicbogosort/
├── .git/                   # Git repository
├── .gitignore              # Git ignore file
├── src/
│   ├── magicbogosort.c      # Core implementation
│   ├── magicbogosort.h      # Header file
│   └── simple_test.c        # Example usage
├── out/                     # Compiled executables and cache
│   ├── magicbogosort        # Compiled executable
│   └── cache.txt           # Magic seed cache (auto-generated)
├── compile.sh              # Build script
├── LICENSE                 # Project license
└── README.md               # This file
```

## 🔧 Building from Source

### Prerequisites

- GCC compiler with C99 support
- Unix-like environment (Linux, macOS, WSL)

### Build Steps

```bash
# Clone the repository
git clone https://github.com/yourusername/magicbogosort.git
cd magicbogosort

# Compile the project
./compile.sh

# Run the example
out/magicbogosort
```

## 💡 Use Cases

- **Educational**: Demonstrates deterministic randomness concepts
- **Research**: Studying relationship between array arrangements and random seeds
- **Fun Projects**: When you need sorting with a touch of magic
- **Benchmarking**: Testing cache performance and seed discovery patterns

## ⚠️ Important Notes

- **Deterministic**: Same array always gets the same magic seed
- **In-Place**: Modifies the original array
- **Unlimited**: Will keep searching until it finds the magic seed
- **Integer Arrays**: Currently supports `int` arrays only

## 🤝 Contributing

Contributions are welcome! Areas for improvement:

- Support for other data types (float, double, char)
- Parallel seed discovery
- Advanced caching strategies
- Performance optimizations

## 📄 License

This project is licensed under the terms in the [LICENSE](LICENSE) file.

## 🎭 The Magic Behind the Magic

Magic Bogosort proves that with enough determination and the right seed, any array can be sorted in exactly one shuffle. It's not about luck—it's about finding that one perfect moment when chaos becomes order.

_"Any sufficiently advanced sorting algorithm is indistinguishable from magic."_ ✨

---

**Made with 🪄 and determination**
