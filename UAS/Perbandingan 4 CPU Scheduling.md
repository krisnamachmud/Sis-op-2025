# Perbandingan 4 Algoritma CPU Scheduling

## Data Proses

| Process | Burst Time | Priority | Arrival Time |
|---------|------------|----------|--------------|
| P₁      | 2          | 2        | 0            |
| P₂      | 1          | 1        | 0            |
| P₃      | 8          | 4        | 0            |
| P₄      | 4          | 2        | 0            |
| P₅      | 5          | 3        | 0            |

**Note:** Higher priority number = Higher priority

## 1. FCFS (First Come First Served)

### Gantt Chart:
```
0     2   3         11      15        20
|P₁---|P₂-|P₃--------|P₄----|P₅------|
```

### Perhitungan:

| Process | Completion Time | Turnaround Time | Waiting Time |
|---------|----------------|-----------------|--------------|
| P₁      | 2              | 2 - 0 = 2       | 2 - 2 = 0    |
| P₂      | 3              | 3 - 0 = 3       | 3 - 1 = 2    |
| P₃      | 11             | 11 - 0 = 11     | 11 - 8 = 3   |
| P₄      | 15             | 15 - 0 = 15     | 15 - 4 = 11  |
| P₅      | 20             | 20 - 0 = 20     | 20 - 5 = 15  |

**Average Waiting Time:** (0 + 2 + 3 + 11 + 15) / 5 = **6.2 ms**

## 2. SJF (Shortest Job First)

**Urutan berdasarkan Burst Time:** P₂(1) → P₁(2) → P₄(4) → P₅(5) → P₃(8)

### Gantt Chart:
```
0   1   3     7       12        20
|P₂-|P₁--|P₄---|P₅-----|P₃-------|
```

### Perhitungan:

| Process | Completion Time | Turnaround Time | Waiting Time |
|---------|----------------|-----------------|--------------|
| P₁      | 3              | 3 - 0 = 3       | 3 - 2 = 1    |
| P₂      | 1              | 1 - 0 = 1       | 1 - 1 = 0    |
| P₃      | 20             | 20 - 0 = 20     | 20 - 8 = 12  |
| P₄      | 7              | 7 - 0 = 7       | 7 - 4 = 3    |
| P₅      | 12             | 12 - 0 = 12     | 12 - 5 = 7   |

**Average Waiting Time:** (1 + 0 + 12 + 3 + 7) / 5 = **4.6 ms**

## 3. Non-Preemptive Priority

**Urutan berdasarkan Priority:** P₃(4) → P₅(3) → P₁(2) → P₄(2) → P₂(1)

**Note:** P₁ dan P₄ sama priority (2), gunakan FCFS untuk tie-breaking

### Gantt Chart:
```
0       8       13  15    19  20
|P₃------|P₅-----|P₁--|P₄---|P₂-|
```

### Perhitungan:

| Process | Completion Time | Turnaround Time | Waiting Time |
|---------|----------------|-----------------|--------------|
| P₁      | 15             | 15 - 0 = 15     | 15 - 2 = 13  |
| P₂      | 20             | 20 - 0 = 20     | 20 - 1 = 19  |
| P₃      | 8              | 8 - 0 = 8       | 8 - 8 = 0    |
| P₄      | 19             | 19 - 0 = 19     | 19 - 4 = 15  |
| P₅      | 13             | 13 - 0 = 13     | 13 - 5 = 8   |

**Average Waiting Time:** (13 + 19 + 0 + 15 + 8) / 5 = **11.0 ms**

## 4. Round Robin (Quantum = 2)

### Eksekusi Step by Step:
- **Time 0-2:** P₁ (2 units, selesai)
- **Time 2-4:** P₂ (1 unit, selesai di time 3)
- **Time 3-5:** P₃ (2 units, remaining = 6)
- **Time 5-7:** P₄ (2 units, remaining = 2)
- **Time 7-9:** P₅ (2 units, remaining = 3)
- **Time 9-11:** P₃ (2 units, remaining = 4)
- **Time 11-13:** P₄ (2 units, selesai)
- **Time 13-15:** P₅ (2 units, remaining = 1)
- **Time 15-17:** P₃ (2 units, remaining = 2)
- **Time 17-18:** P₅ (1 unit, selesai)
- **Time 18-20:** P₃ (2 units, selesai)

### Gantt Chart:
```
0   2 3   5   7   9   11  13  15  17 18  20
|P₁--|P₂|P₃--|P₄--|P₅--|P₃--|P₄--|P₅--|P₃--|P₅|P₃--|
```

### Perhitungan:

| Process | Completion Time | Turnaround Time | Waiting Time |
|---------|----------------|-----------------|--------------|
| P₁      | 2              | 2 - 0 = 2       | 2 - 2 = 0    |
| P₂      | 3              | 3 - 0 = 3       | 3 - 1 = 2    |
| P₃      | 20             | 20 - 0 = 20     | 20 - 8 = 12  |
| P₄      | 13             | 13 - 0 = 13     | 13 - 4 = 9   |
| P₅      | 18             | 18 - 0 = 18     | 18 - 5 = 13  |

**Average Waiting Time:** (0 + 2 + 12 + 9 + 13) / 5 = **7.2 ms**

## Ringkasan Perbandingan

### Turnaround Time:

| Process | FCFS | SJF | Priority | RR |
|---------|------|-----|----------|----| 
| P₁      | 2    | 3   | 15       | 2  |
| P₂      | 3    | 1   | 20       | 3  |
| P₃      | 11   | 20  | 8        | 20 |
| P₄      | 15   | 7   | 19       | 13 |
| P₅      | 20   | 12  | 13       | 18 |

### Waiting Time:

| Process | FCFS | SJF | Priority | RR |
|---------|------|-----|----------|----| 
| P₁      | 0    | 1   | 13       | 0  |
| P₂      | 2    | 0   | 19       | 2  |
| P₃      | 3    | 12  | 0        | 12 |
| P₄      | 11   | 3   | 15       | 9  |
| P₅      | 15   | 7   | 8        | 13 |

### Average Waiting Time:

1. **SJF: 4.6 ms (MINIMUM)**
2. **FCFS: 6.2 ms**
3. **Round Robin: 7.2 ms**
4. **Priority: 11.0 ms**

## Penjelasan Singkat Algoritma

### 1. FCFS (First Come First Served)
**Konsep:** Proses dieksekusi berdasarkan urutan kedatangan (first in, first out).
- **Kelebihan:** Sederhana, mudah diimplementasi, tidak ada starvation
- **Kekurangan:** Convoy effect (proses pendek harus menunggu proses panjang)

### 2. SJF (Shortest Job First)
**Konsep:** Proses dengan burst time terpendek dieksekusi terlebih dahulu.
- **Kelebihan:** Menghasilkan minimum average waiting time
- **Kekurangan:** Starvation untuk proses panjang, perlu prediksi burst time

### 3. Non-Preemptive Priority
**Konsep:** Proses dengan prioritas tertinggi dieksekusi terlebih dahulu.
- **Kelebihan:** Fleksibel berdasarkan importance proses
- **Kekurangan:** Starvation untuk prioritas rendah, priority inversion

### 4. Round Robin
**Konsep:** Setiap proses mendapat time quantum yang sama secara bergiliran.
- **Kelebihan:** Fair sharing, baik untuk time-sharing systems, no starvation
- **Kekurangan:** Context switching overhead, performa bergantung quantum size

## Kesimpulan

**Ranking berdasarkan Average Waiting Time:**
1. **SJF: 4.6 ms** ⭐ (Optimal untuk minimizing waiting time)
2. **FCFS: 6.2 ms** (Simple & predictable)
3. **Round Robin: 7.2 ms** (Fair & responsive)
4. **Priority: 11.0 ms** (Flexible tapi bisa inefficient)

**Key Insights:**
- **SJF** optimal secara teoritis untuk mengurangi waiting time
- **Round Robin** terbaik untuk responsiveness dan fairness
- **FCFS** paling sederhana tapi bisa inefficient dengan convoy effect
- **Priority** memberikan kontrol tapi berisiko starvation

**Pemilihan algoritma** bergantung pada tujuan sistem: minimizing waiting time (SJF), fairness (RR), atau importance-based execution (Priority).memberikan minimum average waiting time untuk set proses yang given.

