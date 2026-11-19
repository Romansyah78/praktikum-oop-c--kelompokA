# Panduan Git (Tahap 1 dan 3)

## Tahap 1 - Leader
1. Buat repository di GitHub bernama `praktikum-oop-c++-kelompok8C`.
2. Settings -> Collaborators -> Add people (4 anggota lain).
3. Dorong struktur awal:
```bash
git init
git add .
git commit -m "Struktur awal proyek"
git branch -M main
git remote add origin https://github.com/<username>/praktikum-oop-c++-kelompok8C.git
git push -u origin main
```

## Tahap 3 - Tiap anggota (branch sendiri lalu Pull Request)
```bash
git checkout -b feature/<peran>      # contoh: feature/lead-programmer
git add .
git commit -m "Deskripsi perubahan"
git push -u origin feature/<peran>
```
Buka Pull Request di GitHub; Integrator (C) mereview lalu merge.

| Anggota | Branch yang disarankan |
|---|---|
| A | feature/header-class |
| B | feature/implementasi-method |
| C | feature/main-menu |
| D | feature/testing |
| E | feature/dokumentasi |
