#### How does OS know what memory is, how to map it?
- Imagine we’re trying to execute a program, say Chrome. How does the OS know where its code and data live?
- The CPU uses a table called the **Global Descriptor Table (GDT)**.
- The GDT is a list of memory *segments* — each describing a chunk of code or data.
- Each entry in the table is **8 bytes**, defining where the segment starts (base), how large it is (limit), and what kind of access it allows.
+------+------+------+------+------+------+------+------+
|Lim0 |Lim1 |Base0|Base1|Base2|Access|Flags+Lim2|Base3|
+------+------+------+------+------+------+------+------+
- **Limit:** how long the segment is.
- **Base:** where it begins in memory.
- **Access/Flags:** what type of segment it is and how it can be used.
