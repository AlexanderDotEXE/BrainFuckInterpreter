# 📚 Project Documentation - BrainfuckMachine

Dieses Dokument bietet eine Übersicht über die Struktur und Funktionsweise des BrainfuckMachine-Projekts, inklusive UML-Diagrammen.

- **.png Dateien**: Exportierte UML-Diagramme für schnelle Referenz.  
- **.drawio Dateien**: Editierbare Diagramme, erstellt in draw.io.  
- **docs.md**: Dieses Dokument.

---

## 🧱 Klassenübersicht

### Band

- **Beschreibung**: Repräsentiert das Memory-Band (Tape) des Brainfuck-Interpreters.  
- **Attribute**:
  - `band`: Array der Zellen
  - `bandSize`: Größe des Bands
  - `bandIndex`: Aktueller Index
- **Methoden**:
  - `increaseBandValue()`, `decreaseBandValue()`
  - `getCurrentBandValue()`, `setCurrentBandValue()`
  - `increaseIndex()`, `decreaseIndex()`

![Band Class Diagram](Band.png)

---

### BrainfuckMachine

- **Beschreibung**: Kernklasse des Interpreters. Führt Brainfuck-Code aus und verwaltet die Programmlogik.  
- **Attribute**:
  - `programCounter`: Aktuelle Position im Programm
  - `band`: Memory-Band
  - `closingBracesSet`, `openingBracesSet`: Lookup für Schleifen
  - `loopIndexStack`: Stack für verschachtelte Schleifen
- **Methoden**:
  - `execute()`: Führt ein Programm aus
  - Private Methoden: `loopBegin()`, `loopEnd()`, `output()`, `isPrintableChar()`, etc.

![BrainfuckMachine Class Diagram](BrainfuckMachine.png)

---

### ProgramLoader

- **Beschreibung**: Hilfsklasse zum Laden und Bereinigen von Brainfuck-Programmen aus Dateien.  
- **Funktionen**:
  - `cleanCode(line: string)`: Entfernt Kommentare und ungültige Zeichen
  - `loadProgramFromFile(filePath: string)`: Lädt das gesamte Programm und bereinigt es

![ProgramLoader Diagram](ProgramLoader.png)

---

## 📌 Hinweise

- Bearbeiten der `.drawio`-Dateien erlaubt es, die Diagramme zu aktualisieren.  
- `.png` Dateien können direkt in Dokumentationen oder GitHub-README eingebunden werden.

---

## 🧑‍💻 Autor

Alexander Gorka
