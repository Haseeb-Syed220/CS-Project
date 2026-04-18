# 🍽️ MESS BILLING SYSTEM

```
███╗   ███╗███████╗███████╗███████╗    ██████╗ ██╗██╗      ██╗      ██╗███╗   ██╗ ██████╗
████╗ ████║██╔════╝██╔════╝██╔════╝    ██╔══██╗██║██║      ██║      ██║████╗  ██║██╔════╝
██╔████╔██║█████╗  ███████╗███████╗    ██████╔╝██║██║      ██║      ██║██╔██╗ ██║██║  ███╗
██║╚██╔╝██║██╔══╝  ╚════██║╚════██║    ██╔══██╗██║██║      ██║      ██║██║╚██╗██║██║   ██║
██║ ╚═╝ ██║███████╗███████║███████║    ██████╔╝██║███████╗███████╗  ██║██║ ╚████║╚██████╔╝
╚═╝     ╚═╝╚══════╝╚══════╝╚══════╝    ╚═════╝ ╚═╝╚══════╝╚══════╝ ╚═╝╚═╝  ╚═══╝ ╚═════╝

███████╗██╗   ██╗███████╗████████╗███████╗███╗   ███╗
██╔════╝╚██╗ ██╔╝██╔════╝╚══██╔══╝██╔════╝████╗ ████║
███████╗ ╚████╔╝ ███████╗   ██║   █████╗  ██╔████╔██║
╚════██║  ╚██╔╝  ╚════██║   ██║   ██╔══╝  ██║╚██╔╝██║
███████║   ██║   ███████║   ██║   ███████╗██║ ╚═╝ ██║
╚══════╝   ╚═╝   ╚══════╝   ╚═╝   ╚══════╝╚═╝     ╚═╝
```

> **A C++ console application for managing hostel/university mess operations — student records, weekly menus, billing, and access control — with automatic file persistence.**

---

## 📋 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Project Structure](#-project-structure)
- [Getting Started](#-getting-started)
- [Default Credentials](#-default-credentials)
- [How It Works](#-how-it-works)
- [File Persistence](#-file-persistence)
- [Known Limitations](#-known-limitations)
- [Bug Fix History](#-bug-fix-history)

---

## 🌟 Overview

The **Mess Billing System** is a terminal-based C++ application designed for hostel and university mess management. It supports two types of users — **Students** and **Managers** — each with their own login and set of actions.

```
┌─────────────────────────────────────────┐
│          MESS BILLING SYSTEM            │
│                                         │
│   System Password ──► Enter App         │
│         │                               │
│    ┌────┴────┐                          │
│    ▼         ▼                          │
│  Student   Manager                      │
│  Login     Login                        │
│    │         │                          │
│    ▼         ▼                          │
│  View      Full                         │
│  Menu    Controls                       │
└─────────────────────────────────────────┘
```

---

## ✨ Features

### 👨‍🎓 Student Portal
| Feature | Description |
|---|---|
| 🔐 Secure Login | Registration number + password verification |
| 🚦 Access Control | Denied students cannot view menu or enter |
| 🍱 View Menu | See today's available dishes and prices |

### 👨‍💼 Manager Portal
| Feature | Description |
|---|---|
| ➕ Add Student | Register a new student with credentials |
| ➖ Remove Student | Remove a student from the system |
| 🧾 Print Bills | View single or all student bills |
| 🍽️ Manage Menu | Add, remove, or set a full weekly menu |
| 🔓 Open / Close Mess | Toggle mess open/closed state |
| 👤 Student Profile | View full profile of any student |
| 💳 Confirm Payment | Reset a student's bill after payment |
| 🔄 Toggle Access | Grant or deny mess access per student |

### 💾 Persistence
| Feature | Description |
|---|---|
| 📂 Auto File Creation | Creates default data files on first run |
| 💾 Auto Save | All changes saved to disk after every manager action |
| 🔄 Auto Load | All data restored automatically on startup |

---

## 📁 Project Structure

```
mess-billing-system/
│
├── main.cpp              ← Full source code
│
├── students.txt          ← Auto-created on first run
│                           Format: reg_no name password bill access
│                           Example: 1001 Ali 1234 0 1
│
├── menu.txt              ← Auto-created on first run
│                           Format: item_name price
│                           Example: Rice 50
│
└── bills.txt             ← Auto-created on first run
                            Format: reg_no bill_amount
                            Example: 1001 0
```

---

## 🚀 Getting Started

### Prerequisites
- A C++ compiler: `g++`, `clang++`, or MSVC
- Terminal / Command Prompt

### Compilation

```bash
# Using g++
g++ -o mess main.cpp

# Using clang++
clang++ -o mess main.cpp
```

### Run

```bash
# Linux / macOS
./mess

# Windows
mess.exe
```

> **Note:** Data files (`students.txt`, `menu.txt`, `bills.txt`) are created automatically in the same directory on first run.

---

## 🔑 Default Credentials

On first run, the system auto-generates these defaults:

```
┌─────────────────────────────────────────┐
│           DEFAULT CREDENTIALS           │
├─────────────────────┬───────────────────┤
│  System Password    │  12345            │
│  Manager Password   │  54321            │
│  Student Reg No.    │  1001             │
│  Student Password   │  1234             │
└─────────────────────┴───────────────────┘
```

> ⚠️ **Change these passwords** in the source code before deploying in a real environment.

---

## 🔄 How It Works

### Login Flow

```
Start
  │
  ▼
Enter System Password (12345)
  │
  ├── Wrong ──► "Invalid system password!" ──► Exit
  │
  ▼
Choose Role: [S]tudent / [M]anager / [X]Exit
  │
  ├── S ──► Enter Reg No ──► Enter Password ──► Check Access ──► View Menu
  │
  ├── M ──► Enter Manager Password (54321) ──► Manager Menu
  │
  └── X ──► Exit
```

### Manager Menu Flow

```
Manager Menu
  │
  ├── 1. Add Student       ──► Input name, reg, password ──► Save
  ├── 2. Remove Student    ──► Input reg no ──► Shift array ──► Save
  ├── 3. Print Bill        ──► Single (S) or All (A)
  ├── 4. Change Menu       ──► Display / Add / Remove / Set Weekly
  ├── 5. Open Mess         ──► messOpen = true
  ├── 6. Close Mess        ──► messOpen = false
  ├── 7. Student Profile   ──► Shows name, reg, bill, access
  ├── 8. Confirm Payment   ──► Resets bill to 0 ──► Save
  └── 9. Toggle Access     ──► IN (grant) / OUT (deny) ──► Save
```

### File Auto-Creation Flow

```
App Starts
  │
  ▼
loadStudents() ──► students.txt exists? ──── No ──► Create with default student (Ali / 1001)
                                         │
                                        Yes
                                         │
                                         ▼
                                   Load all students

loadMenu() ──► menu.txt exists? ──── No ──► Create with Rice/Dal/Chicken defaults
                                 │
                                Yes
                                 │
                                 ▼
                           Load all menu items

loadBills() ──► bills.txt exists? ──── No ──► Create with 0 bill per loaded student
                                   │
                                  Yes
                                   │
                                   ▼
                             Load all bills
```

---

## 💾 File Persistence

All three data files are plain text for easy inspection and editing:

### `students.txt`
```
1001 Ali 1234 0 1
1002 Sara 5678 150 1
1003 Usman 9999 0 0
```
Columns: `reg_no  name  password  bill  access(1=granted/0=denied)`

### `menu.txt`
```
Rice 50
Dal 30
Chicken 120
Biryani 180
```
Columns: `item_name  price`

### `bills.txt`
```
1001 0
1002 150
1003 0
```
Columns: `reg_no  bill_amount`

---

## ⚠️ Known Limitations

| Limitation | Detail |
|---|---|
| Max 100 students | Hard-coded array size |
| Max 21 menu items | 7 days × 3 dishes |
| No bill increment | Student ordering doesn't auto-add to bill yet |
| Plain-text passwords | Stored as integers, not hashed |
| No leap year support | February always assumed to be 28 days |
| Single-word names only | `cin >>` doesn't support spaces in names |

---

## 🐛 Bug Fix History

This project went through **3 rounds of debugging**. Key fixes applied:

| # | Bug | Fix Applied |
|---|---|---|
| 1 | `while(choice != 6)` — char vs int | Changed to `choice != '6'` |
| 2 | `menu[3]`, `price[3]` overflow | Resized to `menu[21]`, `price[21]` |
| 3 | Inner loop `i` shadowed outer `i` | Renamed inner loop to `k` |
| 4 | `choice` uninitialized for student path | Initialized to `'0'` |
| 5 | No exit option — infinite loop | Added `'X'` exit + proper `while` condition |
| 6 | Student password never checked | Added password verification on login |
| 7 | `check_io` never enforced | Added access gate before showing menu |
| 8 | `addStudent()` no bounds check | Added `if (n >= 100)` guard |
| 9 | Files crashed if missing | Added `if (!inFile)` with auto-creation |
| 10 | `loadStudents/Menu` no bounds check | Added `n < 100` / `m < 21` guards |
| 11 | Menu results not copied to globals | Added copy-back loop after `menuFunction` |
| 12 | `messOpen`/`closeMess` had no state | Added `bool messOpen` global |

---

## 👨‍💻 Author

Built as a C++ console application project for hostel/university mess management.

---

*Last updated after full bug-fix pass — all critical and high-severity issues resolved.*
