# 🎵 MP3 Tag Reader (C System-Level Project)

## 📌 Overview
MP3 Tag Reader is a **system-level C application** designed to read and modify metadata (ID3 tags) embedded in MP3 audio files.  
It demonstrates low-level file handling, binary data parsing, and structured manipulation of audio metadata.

This project goes beyond simple file reading by implementing **view, edit, and help functionalities**, making it a practical tool for understanding how media metadata is stored and updated internally.

---

## ⚙️ Features

### 👁️ View MP3 Metadata
Displays important ID3 tags from MP3 files:
- Title
- Artist
- Album
- Year
- Genre
- Comment

### ✏️ Edit MP3 Metadata
Allows modification of existing MP3 tags:
- Updates frame data safely
- Rewrites modified data using a temporary file
- Maintains file integrity during update process

### ❓ Help Module
Provides guidance on how to use the tool and understand available options.

---

## 🛠️ How It Works (Technical Insight)

- Reads MP3 file headers and ID3v2 frames
- Parses binary frame structure (e.g., TIT2, TPE1, TALB, TYER, TCON, COMM)
- Extracts frame size using big-endian conversion
- Performs safe update using **temporary file replacement technique**
- Ensures original file integrity during modification

---

## 🧠 Technologies Used
- C Programming
- File Handling (Binary I/O)
- String Manipulation
- ID3v2 Tag Structure
- Linux Environment

---


---

## 🚀 How to Run

### 1. Clone the repository
```bash
git clone git@github.com:VaishnavTA07/mp3_tag_reader.git
