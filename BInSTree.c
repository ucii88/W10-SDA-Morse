#include <stdio.h>
#include "BinSTree.h"

infotype GetAkar(BinTree P) {
    return Info(P);
}

BinTree GetLeft(BinTree P) {
    return Left(P);
}

BinTree GetRight(BinTree P) {
    return Right(P);
}

address1 AlokasiList(infotype X) {
    address1 P = (address1) malloc(sizeof(ElmtList));  // Alokasi untuk linked list
    if (P != NULL) {
        P->info = X;   // Set informasi
        P->next = NULL; // Pointer next diatur ke NULL
    }
    return P;
}


address Alokasi(infotype X) {
    address P = (address) malloc(sizeof(Node));  // Alokasi untuk tree
    if (P != NULL) {
        P->info = strdup(X);  // Alokasi string untuk info
        P->left = NULL;
        P->right = NULL;
    }
    return P;
}

void BuildMorseTree(BinTree* tree) {
    *tree = Alokasi("Root");

    //  subtree di bawah Root (E dan T)
    Left(*tree) = Alokasi("E");
    Right(*tree) = Alokasi("T");

    //  subtree untuk 'I' dan 'A' di bawah 'E'
    Left(Left(*tree)) = Alokasi("I");
    Right(Left(*tree)) = Alokasi("A");

    //  subtree untuk 'S' dan 'U' di bawah 'I'
    Left(Left(Left(*tree))) = Alokasi("S");
    Right(Left(Left(*tree))) = Alokasi("U");

    //  subtree untuk 'R' dan 'W' di bawah 'A'
    Left(Right(Left(*tree))) = Alokasi("R");
    Right(Right(Left(*tree))) = Alokasi("W");

    //  subtree untuk 'N' dan 'M' di bawah 'T'
    Left(Right(*tree)) = Alokasi("N");
    Right(Right(*tree)) = Alokasi("M");

    //  subtree untuk 'D' dan 'K' di bawah 'N'
    Left(Left(Right(*tree))) = Alokasi("D");
    Right(Left(Right(*tree))) = Alokasi("K");

    //  subtree untuk 'G' dan 'O' di bawah 'M'
    Left(Right(Right(*tree))) = Alokasi("G");
    Right(Right(Right(*tree))) = Alokasi("O");

    //  daun untuk subtree 'S'
    Left(Left(Left(Left(*tree)))) = Alokasi("H");
    Right(Left(Left(Left(*tree)))) = Alokasi("V");
    Left(Right(Left(Left(*tree)))) = Alokasi("F");

    //  daun untuk subtree 'U'
    Right(Right(Left(Left(*tree)))) = Alokasi("L");

    //  daun untuk subtree 'R'
    Left(Left(Right(Left(*tree)))) = Alokasi("P");
    Right(Left(Right(Left(*tree)))) = Alokasi("J");

    //  daun untuk subtree 'W'
    Left(Right(Right(Left(*tree)))) = Alokasi("B");
    Right(Right(Right(Left(*tree)))) = Alokasi("X");

    //  daun untuk subtree 'D'
    Left(Left(Right(Right(*tree)))) = Alokasi("C");
    Right(Left(Right(Right(*tree)))) = Alokasi("Y");

    //  daun untuk subtree 'K'
    Left(Right(Right(Right(*tree)))) = Alokasi("Z");
    Right(Right(Right(Right(*tree)))) = Alokasi("Q");
}

BinTree Tree(infotype Akar, BinTree L, BinTree R) {
    BinTree P = Alokasi(Akar);
    if (P != Nil) {
        Left(P) = L;
        Right(P) = R;
    }
    return P;
}

void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P) {
    *P = Alokasi(Akar);
    if (*P != Nil) {
        Left(*P) = L;
        Right(*P) = R;
    }
}

void BuildTree(BinTree *P) {
    char X[100];
    printf("Masukkan nilai node (9999 untuk node kosong): ");
    scanf("%s", X);

    if (strcmp(X, "9999") == 0) {
        *P = Nil;
    } else {
        *P = Alokasi(X);
        if (*P != Nil) {
            printf("Isi subtree kiri dari node %s:\n", X);
            BuildTree(&Left(*P));
            printf("Isi subtree kanan dari node %s:\n", X);
            BuildTree(&Right(*P));
        }
    }
}


boolean IsUnerLeft(BinTree P) {
    return !IsEmpty(P) && Left(P) != Nil && Right(P) == Nil;
}

boolean IsUnerRight(BinTree P) {
    return !IsEmpty(P) && Left(P) == Nil && Right(P) != Nil;
}

boolean IsBiner(BinTree P) {
    return !IsEmpty(P) && Left(P) != Nil && Right(P) != Nil;
}

boolean IsEmpty(BinTree P) {
    return P == Nil;
}

void PreOrder(BinTree P) {
    if (!IsEmpty(P)) {
        printf("%s ", Info(P));
        PreOrder(Left(P));
        PreOrder(Right(P));
    }
}

void InOrder(BinTree P) {
    if (!IsEmpty(P)) {
        InOrder(Left(P));
        printf("%s ", Info(P));
        InOrder(Right(P));
    }
}

void PostOrder(BinTree P) {
    if (!IsEmpty(P)) {
        PostOrder(Left(P));
        PostOrder(Right(P));
        printf("%s ", Info(P));
    }
}



void PrintNodeLevel(BinTree P, int level) {
    if (IsEmpty(P)) return;

    if (level == 1) {
        printf("Info node           : %s\n", Info(P));
        if (!IsEmpty(Left(P)))
            printf("Info node left son  : %s\n", Info(Left(P)));
        else
            printf("Info node left son  : Tidak ada\n");

        if (!IsEmpty(Right(P)))
            printf("Info node right son : %s\n", Info(Right(P)));
        else
            printf("Info node right son : Tidak ada\n");

        printf("\n");
    } else {
        PrintNodeLevel(Left(P), level - 1);
        PrintNodeLevel(Right(P), level - 1);
    }
}

void PrintTree(BinTree P, int h) {
    int d = Depth(P);
    for (int i = 1; i <= d; i++) {
        printf("Level %d:\n", i);
        PrintNodeLevel(P, i);
    }
}

boolean Search(BinTree P, infotype X) {
    if (IsEmpty(P)) {
        return false;
    }
    if (strcmp(Info(P), X) == 0) {
        return true;
    }
    return Search(Left(P), X) || Search(Right(P), X);
}

int nbElmt(BinTree P) {
    if (IsEmpty(P)) {
        return 0;
    } else {
        return 1 + nbElmt(Left(P)) + nbElmt(Right(P));
    }
}

int nbDaun(BinTree P) {
    if (IsEmpty(P)) {
        return 0;
    } else if (Left(P) == Nil && Right(P) == Nil) {
        return 1;
    } else {
        return nbDaun(Left(P)) + nbDaun(Right(P));
    }
}

boolean IsSkewLeft(BinTree P) {
    if (IsEmpty(P)) {
        return true;
    } else if (Right(P) != Nil) {
        return false;
    } else {
        return IsSkewLeft(Left(P));
    }
}

boolean IsSkewRight(BinTree P) {
    if (IsEmpty(P)) {
        return true;
    } else if (Left(P) != Nil) {
        return false;
    } else {
        return IsSkewRight(Right(P));
    }
}

int Level(BinTree P, infotype X) {
    if (IsEmpty(P)) {
        return 0; // tidak ditemukan
    }

    if (strcmp(Info(P), X) == 0) {
        return 1; // ditemukan di level 1
    }

    int leftLevel = Level(Left(P), X);
    if (leftLevel > 0) {
        return leftLevel + 1;
    }

    int rightLevel = Level(Right(P), X);
    if (rightLevel > 0) {
        return rightLevel + 1;
    }

    return 0; // tidak ditemukan di manapun
}

int Depth(BinTree P) {
    if (IsEmpty(P)) {
        return 0;
    } else {
        return 1 + Max(Depth(Left(P)), Depth(Right(P)));
    }
}

 int Max(int a, int b) {
    return (a > b) ? a : b;
}

void InsertLast(ElmtList **L, infotype X) {
    address1 P = AlokasiList(X);  
    if (P != NULL) {
        if (*L == NULL) {
            *L = P;  
        } else {
            address1 Last = *L;
            while (Last->next != NULL) {  
                Last = Last->next;
            }
            Last->next = P; 
        }
    }
}

void AddDaunTerkiri (BinTree *P, infotype X) {
    if (IsEmpty(*P)) {
        *P = Alokasi(X);
    } else {
        AddDaunTerkiri(&Left(*P), X);
    }
}
void AddDaun (BinTree *P, infotype X, infotype Y, boolean Kiri) {
    if (!IsEmpty(*P)) {
        if (Info(*P) == X && Left(*P) == Nil && Right(*P) == Nil) {
            if (Kiri) {
                Left(*P) = Alokasi(Y);
            } else {
                Right(*P) = Alokasi(Y);
            }
        } else {
            AddDaun(&Left(*P), X, Y, Kiri);
            AddDaun(&Right(*P), X, Y, Kiri);
        }
    }
}

void DelDaunTerkiri (BinTree *P, infotype *X) {
    if (Left(*P) == Nil && Right(*P) == Nil) {
        *X = Info(*P);
        DeAlokasi(*P);
        *P = Nil;
    } else if (Left(*P) != Nil) {
        DelDaunTerkiri(&Left(*P), X);
    } else {
        DelDaunTerkiri(&Right(*P), X);
    }
}

void DelDaun (BinTree *P, infotype X) {
    if (!IsEmpty(*P)) {
        if (Left(*P) == Nil && Right(*P) == Nil && Info(*P) == X) {
            DeAlokasi(*P);
            *P = Nil;
        } else {
            DelDaun(&Left(*P), X);
            DelDaun(&Right(*P), X);
        }
    }
}

ListOfNode MakeListDaun (BinTree P) {
    ListOfNode L = Nil;
    if (!IsEmpty(P)) {
        if (Left(P) == Nil && Right(P) == Nil) {
            InsertLast(&L, Info(P));
        } else {
            ListOfNode LL = MakeListDaun(Left(P));
            ListOfNode LR = MakeListDaun(Right(P));
            if (LL != Nil) {
                L = LL;
                address1 Last = LL;
                while (Next(Last) != Nil) {
                    Last = Next(Last);
                }
                Next(Last) = LR;
            } else {
                L = LR;
            }
        }
    }
    return L;
}

ListOfNode MakeListPreOrder (BinTree P) {
    ListOfNode L = Nil;
    if (!IsEmpty(P)) {
        InsertLast(&L, Info(P));
        ListOfNode LL = MakeListPreOrder(Left(P));
        ListOfNode LR = MakeListPreOrder(Right(P));
        if (L != Nil) {
            address1 Last = L;
            while (Next(Last) != Nil) {
                Last = Next(Last);
            }
            Next(Last) = LL;
            if (LL != Nil) {
                Last = LL;
                while (Next(Last) != Nil) {
                    Last = Next(Last);
                }
                Next(Last) = LR;
            } else {
                Next(Last) = LR;
            }
        }
    }
    return L;
}

void MakeListLevelHelper(BinTree P, int CurrLevel, int TargetLevel, ListOfNode *L) {
    if (!IsEmpty(P)) {
        if (CurrLevel == TargetLevel) {
            InsertLast(L, Info(P));
        } else if (CurrLevel < TargetLevel) {
            MakeListLevelHelper(Left(P), CurrLevel + 1, TargetLevel, L);
            MakeListLevelHelper(Right(P), CurrLevel + 1, TargetLevel, L);
        }
    }
}

ListOfNode MakeListLevel (BinTree P, int N) {
    ListOfNode L = Nil;
    MakeListLevelHelper(P, 1, N, &L);
    return L;
}

boolean BSearch (BinTree P, infotype X) {
    if (IsEmpty(P)) {
        return false;
    } else if (Info(P) == X) {
        return true;
    } else if (X < Info(P)) {
        return BSearch(Left(P), X);
    } else {
        return BSearch(Right(P), X);
    }
}

address BinSearch (BinTree P, infotype X) {
    if (IsEmpty(P)) {
        return Nil;
    } else if (Info(P) == X) {
        return P;
    } else if (X < Info(P)) {
        return BinSearch(Left(P), X);
    } else {
        return BinSearch(Right(P), X);
    }
}

void InsSearch (BinTree *P, infotype X) {
    if (IsEmpty(*P)) {
        *P = Alokasi(X);
    } else if (X < Info(*P)) {
        InsSearch(&Left(*P), X);
    } else if (X > Info(*P)) {
        InsSearch(&Right(*P), X);
    }
}

void DestroyTree(BinTree *P) {
    if (!IsEmpty(*P)) {
        DestroyTree(&Left(*P));
        DestroyTree(&Right(*P));
        DeAlokasi(*P);
        *P = Nil;
 }
}

void DelNode (BinTree *P) {
    if (Right(*P) != Nil) {
        DelNode(&Right(*P));
    } else {
        BinTree Q = *P;
        *P = Left(*P);
        DeAlokasi(Q);
    }
}

void DeAlokasi (address P) {
    if (P != Nil) {
        free(P->info); 
        free(P);
    }
}

// Fungsi untuk menampilkan huruf dan kode Morse-nya
void printMorseCode(BinTree P, char* code, int level) {
    if (IsEmpty(P)) {
        return;
    }
    
    if (Info(P)[0] != ' ') {
        printf("%c: %s\n", Info(P), code);
    }
    
    char leftCode[100];
    strcpy(leftCode, code);
    strcat(leftCode, ".");
    printMorseCode(Left(P), leftCode, level + 1);
    
    char rightCode[100];
    strcpy(rightCode, code);
    strcat(rightCode, "-");
    printMorseCode(Right(P), rightCode, level + 1);
}

// Fungsi untuk decoding karakter Morse
char* decodeMorse(BinTree root, char* code) {
    BinTree current = root;
    
    // Traversal berdasarkan kode
    for (int i = 0; i < strlen(code); i++) {
        if (code[i] == '.') {
            // Ke kiri untuk titik
            if (Left(current) == Nil) {
                return NULL; 
            }
            current = Left(current);
        } else if (code[i] == '-') {
            // Ke kanan untuk dash
            if (Right(current) == Nil) {
                return NULL; 
            }
            current = Right(current);
        } else {
            return NULL; 
        }
    }
    
    return Info(current);  
}

// Fungsi untuk encoding karakter ke Morse
void findMorseCode(BinTree node, char target, char* result, char* currentCode) {
    if (IsEmpty(node)) {
        return;
    }
    
    if (Info(node)[0] == target) {
        strcpy(result, currentCode);
        return;
    }
    
    // Coba ke kiri
    char leftCode[100];
    strcpy(leftCode, currentCode);
    strcat(leftCode, ".");
    findMorseCode(Left(node), target, result, leftCode);
    
    // Coba ke kanan kalo belum ketemu
    if (strlen(result) == 0) {
        char rightCode[100];
        strcpy(rightCode, currentCode);
        strcat(rightCode, "-");
        findMorseCode(Right(node), target, result, rightCode);
    }
}

// Fungsi untuk mengkonversi teks ke kode Morse
void textToMorse(BinTree root, char* text, char* result) {
    result[0] = '\0';
    char morseChar[100];
    
    for (int i = 0; i < strlen(text); i++) {
        morseChar[0] = '\0';
        findMorseCode(root, toupper(text[i]), morseChar, "");
        
        if (strlen(morseChar) > 0) {
            strcat(result, morseChar);
            strcat(result, " ");
        }
    }
}

// Fungsi untuk mengkonversi kode Morse ke teks
void morseToText(BinTree root, char* morse, char* result) {
    result[0] = '\0';
    char* token = strtok(morse, " ");
    
    while (token != NULL) {
        char *c = decodeMorse(root, token);
        if (c != NULL && c[0] != '\0') {
            char charStr[2] = {c[0], '\0'};
            strcat(result, charStr);
        }
        token = strtok(NULL, " ");
    }
}

void convertFileToMorse(BinTree morseTree, const char *inputFile, const char *outputFile) {
    FILE *fin, *fout;
    char line[100];
    char result[1000];  

    fin = fopen(inputFile, "r");
    fout = fopen(outputFile, "w");

    if (fin == NULL || fout == NULL) {
        printf("Error membuka file!\n");
        return;
    }

    
    while (fgets(line, sizeof(line), fin)) {
        textToMorse(morseTree, line, result);  
        fprintf(fout, "%s\n", result);  
    }

    
    printf("Konversi file berhasil!\n");

    fclose(fin);
    fclose(fout);
}