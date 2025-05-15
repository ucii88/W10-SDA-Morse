#include "BinSTree.h"


int main() {
    BinTree morseTree = Nil;
    int choice;
    char input[100], result[500];
    
    BuildMorseTree(&morseTree);
    // Menu utama
    do {
        printf("\n===== PROGRAM MORSE TREE =====\n");
        printf("1. Insert node\n");
        printf("2. Print Tree\n");
        printf("3. Traversal PreOrder\n");
        printf("4. Traversal InOrder\n");
        printf("5. Traversal PostOrder\n");
        printf("6. Traversal LevelOrder\n");
        printf("7. Search Node Tree\n");
        printf("8. Jumlah Daun/Leaf\n");
        printf("9. Mencari Kedalaman Node Tree\n");
        printf("10. Membandingkan 2 Node Tree\n");
        printf("11. Konversi Teks ke Morse\n");
        printf("12. Konversi Morse ke Teks\n");
        printf("13. Tampilkan Kode Morse Semua Karakter\n");
        printf("14. Konversi File Teks ke Morse\n"); // Menu baru
        printf("15. Exit\n");
        printf("Pilihan: ");
        scanf("%d", &choice);
        getchar(); // Ambil karakter newline
        
        switch (choice) {
            case 1: {
                // Insert node
            }
            break;
        
            case 2:
                // Print Tree
            break;
                
            case 3:
                // Traversal PreOrder
            break;
                
            case 4:
                // Traversal InOrder
            break;
                
            case 5:
                // Traversal PostOrder
            break;
                
            case 6:
                // Implementasi level order traversal (BFS)
            break;
                
            case 7:
                // Search Node Tree
            break;
                
            case 8:
                // Jumlah Daun/Leaf
            break;
                
            case 9:
                // Mencari Kedalaman Node Tree
            break;
                
            case 10:
                // Membandingkan 2 Node Tree
            break;

                
            case 11:
                // Konversi Teks ke Morse
            break;
                
            case 12:
                // Konversi Morse ke Teks
            break;
                
            case 13:
                // Tampilkan semua kode Morse
            break;
                
            case 14:
                 // Konversi File Teks ke Morse
            break;
            
            case 15:
                // Exit logic
                printf("Terima kasih telah menggunakan program Morse Tree!\n");
            break;
        }
        
    } while (choice != 15);
    
  return 0;
}
