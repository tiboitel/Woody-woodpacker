# Woody-woodpacker

Woody-woodpacker is a binary packer designed to encrypt executable files in Mach-O and ELF64 formats. The packed binaries are capable of decrypting themselves at runtime, ensuring seamless execution post-encryption.

## Features

- **Encryption Support**: Encrypts executables in both Mach-O and ELF64 formats.
- **Self-Decryption**: Generated binaries include mechanisms to decrypt themselves during execution.

## Getting Started

### Prerequisites

- A Unix-like operating system (e.g., Linux, macOS).
- GCC compiler.
- GNU Make.

### Installation

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/tiboitel/Woody-woodpacker.git
   ```

2. **Navigate to the Project Directory**:

   ```bash
   cd Woody-woodpacker
   ```

3. **Build the Project**:

   ```bash
   make
   ```

## Usage

To pack an executable, run the following command:

```bash
./woody_woodpacker /path/to/executable
```

This command will generate an encrypted version of the specified executable in the current directory.

## Contributing

Contributions are welcome! Please fork the repository and create a new branch for any feature additions or bug fixes. Submit a pull request with a detailed description of your changes.

## License

This project is licensed under the GNU General Public License v3.0. See the [LICENSE](LICENSE) file for more details.

---

*Note: Ensure you have the necessary permissions to encrypt and distribute any executable files you process with Woody-woodpacker.* 
