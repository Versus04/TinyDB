<div align="center">

# 🗄️ TinyDB

### ⚡ A Lightning-Fast, In-Memory SQL Database Engine

*Built from scratch in modern C++ for developers who need speed and simplicity*

[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)](https://github.com)
[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://isocpp.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](http://makeapullrequest.com)

[🚀 Quick Start](#-quick-start) • [📖 Documentation](#-usage) • [🎯 Examples](#-example-session) • [🛠️ Contributing](#-future-enhancements)

</div>

---

## ✨ Why TinyDB?

🎯 **Zero Dependencies** - No external libraries, just pure C++  
⚡ **Blazing Fast** - In-memory operations with hash-based storage  
🔧 **Easy to Embed** - Drop into any C++ project  
📚 **SQL Compatible** - Familiar syntax, no learning curve  
🐣 **Lightweight** - Minimal footprint, maximum performance  

## 🚀 Quick Start

Get up and running in under 2 minutes:

```bash
git clone https://github.com/Versus04/TinyDB
cd TinyDB && mkdir build && cd build
cmake .. 
cmake --build

```

*That's it! Start querying immediately.*

## 🎬 See It In Action

```sql
db> CREATE TABLE products (id INT, name TEXT, price DECIMAL)
    Table 'products' created successfully.

db> INSERT INTO products VALUES (1, 'Laptop', 999.99)
     Data inserted successfully.

db> SELECT * FROM products;
┌────┬────────┬────────┐
│ id │ name   │ price  │
├────┼────────┼────────┤
│ 1  │ Laptop │ 999.99 │
└────┴────────┴────────┘
```

## 🛠️ Building the Project

### Prerequisites
- 🔧 CMake 3.10+
- 💻 C++17 compiler (GCC/Clang/MSVC)
- 🪟 MinGW (Windows only)
## 📖 Usage

### 🎯 Core Commands

| Command | Description | Example |
|---------|-------------|---------|
| `CREATE TABLE` | Define new table structure | `CREATE TABLE users (id INT, name TEXT)` |
| `INSERT INTO` | Add data to tables | `INSERT INTO users VALUES (1, 'Alice')` |
| `SELECT` | Query and retrieve data | `SELECT name FROM users` |
| `EXIT` | Close the database | `EXIT` |

### 💡 Pro Tips
- 🔥 Use `SELECT *` for quick data exploration
- 📊 Table names are case-sensitive

## 🎯 Example Session

```sql
db> CREATE TABLE employees (id INT, name TEXT, department TEXT, salary INT);
     Table 'employees' created successfully.

db> INSERT INTO employees VALUES (1, 'Sarah Connor', 'Engineering', 75000);
     Data inserted successfully.

db> INSERT INTO employees VALUES (2, 'John Smith', 'Marketing', 65000);
     Data inserted successfully.

db> SELECT name, salary FROM employees;
┌──────────────┬────────┐
│ name         │ salary │
├──────────────┼────────┤
│ Sarah Connor │ 75000  │
│ John Smith   │ 65000  │
└──────────────┴────────┘

db> EXIT;   
    Exiting Database....
```

## 🏗️ Architecture

### 🧩 Core Components
- 🗄️ **Database Engine**: Hash-based table management and command execution
- 🔍 **SQL Parser**: Intelligent command parsing with error handling
- 📋 **Command Processor**: Structured representation of SQL operations
- 📊 **Table Manager**: Efficient column and row operations

### ⚠️ Current Limitations
- 💾 **No Persistence**: Data lives in memory only (perfect for testing!)
- 🎯 **Basic Filtering**: WHERE clauses coming soon
- 🔗 **Single Tables**: JOINs in development
- 📝 **Simple Types**: Advanced data validation planned

## 🚀 What's Coming Next?

| Feature | Status | Priority |
|---------|--------|----------|
| 💾 File Persistence | 🔄 In Progress | High |
| 🔍 WHERE Clauses | 📋 Planned | High |
| ✏️ UPDATE/DELETE | 📋 Planned | Medium |
| 🔗 JOIN Operations | 💭 Research | Medium |
| 📊 Indexing | 💭 Research | Low |

## 🤝 Contributing

We love contributions! Here's how you can help:

1. 🍴 Fork the repository
2. 🌿 Create a feature branch (`git checkout -b amazing-feature`)
3. 💾 Commit your changes (`git commit -m 'Add amazing feature'`)
4. 📤 Push to the branch (`git push origin amazing-feature`)
5. 🎉 Open a Pull Request

## 📄 License

Released under the [MIT License](https://opensource.org/licenses/MIT) - see `LICENSE` file for details.

---

<div align="center">

**⭐ Star this repo if you find it useful!**
</div>