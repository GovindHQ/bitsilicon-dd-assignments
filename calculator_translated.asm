.DATA 

; STORE VALUES OF PORTS 
	PORTA_VAL DB 0
    PORTB_VAL DB 0
    PORTC_VAL DB 0  
    
;STRINGS FOR LCD DISPLAY

    MYSTR	DB	"HOA HONG NHO$"   
    NUT DB "NUT 16$"    
    INF DB "INF$"
    SANS DB "ANS$"   ; STIRNG DE HIEN RA MAN HINH CHU ANS  
    ERROR   DB  "ERROR$" 
    TRY_STR DB "PLEASE TRY AGAIN$" 
;PORT ADDRESSES 
    PA EQU 00H 	
	PB EQU 02H 	    ; CAC PORT ADDRESSES 
	PC EQU 04H                    
	
	CWR   EQU 06H	; DIA CHI CAU HINH 8255
; VARIABLES FOR OPERANDS 
	
    NUM1 DW 0     
    
    NUM2 DW 0

	RESULT DW 0 
	
	ANS DW 0  ; LUU RESULT CU CUA PHEP TINH
	
	CANS DW 0 ; LUU GIA TRI SAU OPERATOR CFUNCTION  
    
    
    BD DB 0   ; BUTTON STATE
    
    OPERATOR DB 0  ; OPERATOR CUA OPERATION 
    
    KNUMBER DW 0  ; NUMBER INPUT LIEU TU BAN PHIM 
    
    SIGN DW 0 ; CO BAO AM 
    
    FFLAG DB 0 ; CO BAO INPUT NUMBER AM LAN OPERATOR
    
    SIGN_FLAG DB 0; CO BAO THUC HIEN PHEP TINH AM  

    
    N_COUNT DB 0  ; BAO XEM NUMBER DO CO BAO NHIEU CHU NUMBER 
    
    
    ; VARIABLES FOR DIVISION 
    
    ; DIVISION PRODUCES DECIMAL 
    
    
    CRESULT DW 0  ; BIEN LUU NUMBER DU SAU PHEP CHIA DE TINH TOAN 
    CDOT DB 0     ; CO BAO PHEP TINH NUMBER THUC
    
    N DW 0  

.STACK 100H 

;****************************************************************************
.CODE
 
PROC MAIN
; TRO TOI DU LIEU DATA 
    MOV AX, @DATA
    MOV DS, AX
    MOV ES, AX  

    
;CONFIGURE PORTS 
    MOV DX,CWR
    MOV AL,88H   ;PORTA, PORTB, PORT C LOWER LA OUTPUPT, PORTC UPPER LA INPUT

    OUT DX,AL  

	
	
	; LCD INITIALIZATION FUNCTION 	  

	CALL LCD_INIT	
	
    
    
    
	MOV DL,1   ; SET ROW
	MOV DH,3   ; SET COLUMN 
	CALL LCD_SET_CUR     	
	LEA SI,MYSTR    
	CALL LCD_WRITE_STR

	
	MOV DL,2 
	MOV DH, 6 
	CALL LCD_SET_CUR  
	LEA SI,NUT
	CALL LCD_WRITE_STR
	

    MOV CX, 60000
    CALL DELAY    
    
    MOV CX, 60000
    CALL DELAY   
    CALL LCD_CLEAR 
    
    
    
    
    MOV DL,1 
    MOV DH,1 
    CALL LCD_SET_CUR
    


;***********************************************
;CALL KEYPAD 

;;;;;;    KEYPAD SCANNING   ;;;;;;;    
KEYPAD: 

    ;**********************************
    ; CHECK HANG THU NHAT 
    MOV AL, 11111110B
    OUT PC, AL
    MOV CX, 250
    CALL DELAY 

    IN AL,PC    ; LAY DU LIEU TAI PORTC
    
    
    ;********* CHECK CAC NUT 
    CMP AL, 11101110b ; CHECK CO NHAN NUMBER 7 KHONG 
    JNE N7
    
        CMP BD, 1
        JE  KEYPAD
        
            MOV AH, '7'
            CALL LCD_WRITE_CHAR 
            MOV FFLAG, 1 ; XAC NHAN KHONG INPUT OPERATOR VAO AM 
            
            MOV KNUMBER, 7
            MOV BD, 1
            JMP INPUT_NUM   
; NHAY NEU KHONG NHAN NUMBER 7    
N7:
    CMP AL, 11011110b ; CHECK NUMBER 8
    JNE N8   
    
        CMP BD, 1
        JE  KEYPAD
        
            MOV AH, '8'
            CALL LCD_WRITE_CHAR
            MOV FFLAG, 1
            
            MOV KNUMBER, 8
            MOV BD, 1
            JMP INPUT_NUM
           
; NHAY DEN DAY NEU KHONG NHAN NUMBER 8     
N8:
    CMP AL, 10111110b ; CHECK NUMBER 9 
    JNE N9  
    
        CMP BD, 1
        JE  KEYPAD
        
            MOV AH, '9'
            CALL LCD_WRITE_CHAR 
            MOV FFLAG, 1
            
            MOV KNUMBER, 9
            MOV BD, 1
            JMP INPUT_NUM
        
N9:
    CMP AL, 01111110b ; OPERATOR CHIA
    JNE NCHIA 
    
        CMP BD, 1
        JE  KEYPAD  
        
            MOV AH, '/'
            CALL LCD_WRITE_CHAR 
            CMP OPERATOR, 0 ; CHECK XEM CO OPERATOR LA KHONG VX -* +* /*   
            JNE INPUT_LOI
            
            
            MOV OPERATOR, '/'     
            
            MOV BD, 1  
        
            JMP KEYPAD
      
    ;**********************************
    ;                                 ;
    ;                                 ;
    ;**********************************       
     
    ; CHECK HANG THU HAI
NCHIA: 

    MOV AL, 11111101b
    OUT PC, AL
    MOV CX, 250
    CALL DELAY 

    IN AL,PC    ; LAY DU LIEU TAI PORTC
    
    
    ;********* CHECK CAC NUT 
    CMP AL, 11101101b ; CHECK CO NHAN NUMBER 4 KHONG 
    JNE N4
    
        CMP BD, 1
        JE  KEYPAD
        
        MOV AH, '4'
        CALL LCD_WRITE_CHAR  
        MOV FFLAG, 1
        
        MOV KNUMBER, 4
        MOV BD, 1
        JMP INPUT_NUM   
; NHAY NEU KHONG NHAN NUMBER 7    
N4:
    CMP AL, 11011101b ; CHECK NUMBER 5
    JNE N5
        CMP BD, 1
        JE  KEYPAD
        
        MOV AH, '5'
        CALL LCD_WRITE_CHAR 
        MOV FFLAG, 1
        
        MOV KNUMBER, 5
        MOV BD, 1
        JMP INPUT_NUM
           
; NHAY DEN DAY NEU KHONG NHAN NUMBER 8     
N5:
    CMP AL, 10111101b ; CHECK NUMBER 6
    JNE N6
    
        CMP BD, 1
        JE  KEYPAD
        
        MOV AH, '6'
        CALL LCD_WRITE_CHAR
        MOV FFLAG, 1
        
        MOV KNUMBER, 6
        MOV BD, 1
        JMP INPUT_NUM
        
N6:
    CMP AL, 01111101b ; OPERATOR NHAN
    JNE NNHAN
    
    CMP BD, 1
    JE  KEYPAD
        MOV AH, '*'
        CALL LCD_WRITE_CHAR 
        
        CMP OPERATOR, 0 ; CHECK XEM CO OPERATOR LA KHONG VX -* +* /*   
        JNE INPUT_LOI
        
        MOV OPERATOR, '*'     
        
        MOV BD, 1  
    
        JMP KEYPAD
        
        
 
    ;**********************************
    ;                                 ;
    ;                                 ;
    ;**********************************       
     
    ; CHECK HANG THU BA
NNHAN: 

    MOV AL, 11111011b
    OUT PC, AL
    MOV CX, 250
    CALL DELAY 

    IN AL,PC    ; LAY DU LIEU TAI PORTC
    
    
    ;********* CHECK CAC NUT 
    CMP AL, 11101011b ; CHECK CO NHAN NUMBER 1 KHONG 
    JNE N1
    
        CMP BD, 1
        JE  KEYPAD
        
        MOV AH, '1'
        CALL LCD_WRITE_CHAR  
        MOV FFLAG, 1
        
        MOV KNUMBER, 1
        MOV BD, 1
        JMP INPUT_NUM   
; NHAY NEU KHONG NHAN NUMBER 7    
N1:
    CMP AL, 11011011b ; CHECK NUMBER 2
    JNE N2
        CMP BD, 1
        JE  KEYPAD
        
        MOV AH, '2'
        CALL LCD_WRITE_CHAR
        MOV FFLAG, 1
        
        MOV KNUMBER, 2
        MOV BD, 1
        JMP INPUT_NUM
           
; NHAY DEN DAY NEU KHONG NHAN NUMBER 8     
N2:
    CMP AL, 10111011b ; CHECK NUMBER 3
    JNE N3
    
        CMP BD, 1
        JE  KEYPAD
        
            MOV AH, '3'
            CALL LCD_WRITE_CHAR
            MOV FFLAG, 1
            
            MOV KNUMBER, 3
            MOV BD, 1
            JMP INPUT_NUM
        
N3:
    CMP AL, 01111011b ; OPERATOR TRU
    JNE NTRU
    
        CMP BD, 1
        JE  KEYPAD 
        
            MOV AH, '-'
            CALL LCD_WRITE_CHAR  
            
            CMP FFLAG, 0 ; CHECK CO DANG INPUT AM HAY KHONG
            JNE N_I_S 
            
            ; NEU INPUT VAO CO OPERATOR 
            MOV SIGN_FLAG, 1
            MOV OPERATOR, 0
            MOV BD, 1  
            
            JMP KEYPAD ; CHAY VE FUNCTION QUET BAM PHIM 
            
            
        N_I_S: 
            ;;; TRONG HOP INPUT CONG TRUOC TRU SAU 
            CMP OPERATOR, '+'
            JNE KT_TRU
            MOV OPERATOR, '-' 
            MOV BD, 1
            JMP KEYPAD   
            
             
        KT_TRU:  
            ;;;  TRUONG HOP INPUT HAI OPERATOR TRU ;;;;
            CMP OPERATOR, '-'  ; CHECK TRUONG HOP INPUT 2 OPERATOR AM     
            JNE KT_NHAN     ; NHAY TRUONG HOP KHONG PHAI HAI OPERATOR 
            MOV OPERATOR, '+'  ; HAI OPERATOR TRU THANH CONG
            MOV BD, 1     ; TRANH BI LAP LAI OPERATOR 
            JMP KEYPAD 
            
        KT_NHAN: 
            CMP OPERATOR, '*' 
            JNE KT_CHIA 
            
            JMP INPUT_LOI    
            
        KT_CHIA:
            CMP OPERATOR, '/' 
            JNE  N_D_S          
            JMP INPUT_LOI  
                
        N_D_S:     
            MOV OPERATOR, '-'       
            MOV BD, 1       
            JMP KEYPAD   
            
    ;**********************************
    ;                                 ;
    ;                                 ;
    ;**********************************       
     
    ; CHECK HANG THU TU
NTRU: 

    MOV AL, 11110111b
    OUT PC, AL
    MOV CX, 250
    CALL DELAY 

    IN AL,PC    ; LAY DU LIEU TAI PORTC
    
    
    ;********* CHECK CAC NUT 
    CMP AL, 11100111b ; CHECK CO NHAN C KHONG 
    JNE NC  
    
        C:
    
        CALL LCD_CLEAR           
        
        ; RESET TAT CA CAC THONG NUMBER 
        MOV NUM1, 0 
        MOV NUM2, 0 
        MOV RESULT, 0 
        MOV OPERATOR, 0 
        MOV KNUMBER, 0       
        MOV SIGN,0         
        MOV CRESULT, 0 
        MOV N_COUNT, 0        
        MOV CDOT, 0 
        MOV FFLAG, 0 ; RESET BIEN XAC NHAN   
        MOV BD, 1          
        JMP KEYPAD    
            
NC:
    CMP AL, 11010111b ; CHECK NUMBER 0
    JNE N0   
    
        CMP BD, 1
        JE  KEYPAD
        
            MOV AH, '0'
            CALL LCD_WRITE_CHAR 
            MOV FFLAG, 1
            
            MOV KNUMBER, 0
            MOV BD, 1
            JMP INPUT_NUM
               
   
N0:
    CMP AL, 10110111b ; BANG
    JNE NBANG
    
        CMP BD, 1
        JE  KEYPAD
        
            MOV BD, 1    
            JMP CACULATE
        
NBANG:
    CMP AL, 01110111b  ; OPERATOR CONG
    JNE NCONG
    
    CMP BD, 1
    JE  KEYPAD 
    
        MOV AH, '+'
        CALL LCD_WRITE_CHAR
        
        CMP OPERATOR, '-'
        
        JNE TRU_CONG
        
        MOV OPERATOR, '-' 
        MOV BD, 1
        JMP KEYPAD 
         
    TRU_CONG:    
        MOV OPERATOR, '+'     
        
        MOV BD, 1  
    
        JMP KEYPAD    
NCONG: 
    
    MOV BD, 0 
    JMP KEYPAD  
    
;;    FUNCTION XU LY KHI INPUT LOI  ;;;; 
INPUT_LOI:    

    LEA SI, ERROR
    CALL LCD_WRITE_STR
    
    
    
    MOV DL,2   ; SET ROW
	MOV DH,1   ; SET COLUMN 
	CALL LCD_SET_CUR     	
	LEA SI,TRY_STR   
	CALL LCD_WRITE_STR  
	
	MOV CX, 60000 
	CALL DELAY
	
	JMP C
    
      
;*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
;                                            ;
;                 INPUT KEYPAD               ;
;                                            ;
;*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*

INPUT_NUM:  

    CMP OPERATOR, 0
    
    JE LNUM1
    
    
    JMP LNUM2    

;*******************************************
                                           ;
LNUM1:                                     ;
    CMP NUM1, 0                            ;
                                           ;
    JNE NOT0N1                             ;
                                           ;
        MOV AX, KNUMBER                        ;
                                           ;
        MOV NUM1, AX                       ;
                                           ;
        JMP EXITN1                         ;
                                           ;
    NOT0N1:                                ;
                                           ;
        MOV AX, NUM1                       ;
                                           ;
        MOV BX, 10                         ;
                                           ;
        MUL BX                             ;
                                           ;
        ADD AX, KNUMBER                        ;
                                           ;
        MOV NUM1, AX                       ;
                                           ;
    EXITN1:                                ;
        JMP KEYPAD                         ;
                                           ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;                                   
                                           ;
LNUM2:                                     ;
    CMP NUM2, 0                            ;
                                           ;
    JNE NOT0N2                             ;
                                           ;
        MOV AX, KNUMBER                        ;
                                           ;
        MOV NUM2, AX                       ;
                                           ;
        JMP EXITN2                         ;
                                           ;
    NOT0N2:                                ;
                                           ;
        MOV AX, NUM2                       ;
                                           ;
        MOV BX, 10                         ;
                                           ;
        MUL BX                             ;
                                           ;
        ADD AX, KNUMBER                        ;
                                           ;
        MOV NUM2, AX                       ;
                                           ;
    EXITN2:                                ;
        JMP KEYPAD                         ;
                                           ;                                      
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; 

                 
CACULATE: 

; TINH TOAN RESULT 
    ; DUA CON TRO CUA LCD VE VI TRI CHINH 
    CMP SIGN_FLAG, 1  ; CO BAO INPUT AM  
    
    JNE N_C_S 
    
    
    CMP OPERATOR,'+' 
    JNE N_C 
    
    ; NEU LA PHEP CONG CO OPERATOR DUNG TRUOC AM 
    ; DAO HAI NUMBER ROI THUC HIEN PHEP TRU 
    
    MOV CX, NUM1 
    
    MOV BX, NUM2
    
    MOV NUM1, BX
    
    MOV NUM2, CX 
    MOV SIGN, 0 ; TAT CO BAO OPERATOR  
    MOV SIGN_FLAG, 0 ; TAT CO BAO AM 
    JMP TRU
    
N_C:
    CMP OPERATOR, '-'
    JNE N_DIV
    
    MOV SIGN, 1  
    MOV SIGN_FLAG, 0 ; TAT CO BNAO NUMBER AM DI
    JMP CONG
N_DIV: 
    CMP OPERATOR, '*' 
    JNE N_MUL 
    
    MOV SIGN, 1
    MOV SIGN_FLAG, 0
    JMP NHAN 
    
N_MUL:
    CMP OPERATOR, '/'
    JNE KHONG_S
    
    MOV SIGN, 1
    MOV SIGN_FLAG, 0 
    JMP CHIA    
    
    
N_C_S: 
        
    CMP OPERATOR, '+' 
    JE CONG      
    
    CMP OPERATOR, '-' 
    JE TRU
    
    CMP OPERATOR, '*' 
    JE NHAN
    
    CMP OPERATOR, '/' 
    JE CHIA  
    
KHONG_S:    
	LEA SI,ERROR
	CALL LCD_WRITE_STR 
	
	JMP KEYPAD

;------------------------------------------- 
      ; THUC HIEN PHEP TINH CONG ; 

CONG: 

    MOV AX, NUM1
    
    MOV BX, NUM2
    
    ADD AX, BX
     
    MOV RESULT, AX
    
    MOV ANS, AX
    
    JMP HNUM

;-------------------------------------------
      ; THUC KIEN PHEP TINH TRU ; 

TRU:
    CMP SIGN, 1  
    
    JNE THAN 
    
    MOV CX, NUM1 
    
    MOV BX, NUM2
    
    MOV NUM1, BX
    
    MOV NUM2, CX
    
    
    XOR CX, CX 
    XOR BX, BX    
    
THAN: 
    MOV AX, NUM1 
    
    MOV BX, NUM2 
        
    
    CMP AX, BX
    
    JB TRUAM  ; TRUONG HOP NUM1 NHO  HON NUM2 OPERATION AM   
    
    SUB AX, BX
     
    MOV RESULT, AX
    
    MOV ANS, AX 
    
    MOV SIGN, 0
    
    JMP HNUM 
    
    
        
TRUAM: 
    MOV AX, NUM2 
    MOV BX, NUM1
    
    SUB AX, BX
    
    MOV RESULT, AX  ; LUU RESULT
    
    MOV ANS, AX
    
    MOV SIGN, 1 

    
    JMP HNUM  
     
;-------------------------------------------
    
NHAN:    
    
    MOV AX, NUM1 
    
    MOV BX, NUM2 
    
    MUL BX
     
    MOV RESULT, AX 
    
    MOV ANS, AX
    
    JMP HNUM
;------------------------------------------- 
     ; THUC HIEP OPERATION CHIA    
CHIA:   
    
    MOV DX, 0  ; THI GHI QUAN TRONG TRONG QUA TRINH CHIA   
      
    MOV AX, NUM1   
    
    CMP NUM2, 0 
    
    JNE TIEPC 
    
    
    ; NEU NUMBER CHIA LAF 0 
    
    MOV DL, 2
    
    MOV DH, 14
    
    CALL LCD_SET_CUR 
    
    LEA SI, INF
    
    CALL LCD_WRITE_STR
    
    JMP KEYPAD
    
TIEPC: 
    
    MOV BX, NUM2 
    
    DIV BX    
    
    MOV RESULT, AX
    
    MOV ANS, AX
    
    MOV CRESULT, DX    
    
    
    CMP CRESULT, 0   ; CHECK XEM PHEP CHIA NAY CO DU HAY KHONG 
    
    JNE FLOAT    ; PHEP CHIA CO NUMBER THUC 
     
     
     
    JMP HNUM ; NEU KHONG CO NUMBER THUC THI IN BINH THUONG           
;-------------------------------------------       
FLOAT: 
    MOV CDOT, 1
    
    JMP HNUM
    
;-------------------------------------------        



    
;-------------------------------------------
HNUM:  
    
    CMP RESULT, 10000    
    JNB NUMBERL5  


    CMP RESULT, 1000  
    JNB NUMBERL4
    
    
    CMP RESULT, 100
    JNB NUMBERL3
    
    
    CMP RESULT, 10
    JNB NUMBERL2  
    
    
    
    MOV N_COUNT, 1 
    
    
    CMP CDOT, 1 ; CHECK OPERATION FLOAT 
    JNE NF1     
    
    
    MOV DL,2
	MOV DH,11
	CALL LCD_SET_CUR 
	
	CMP SIGN, 0  ; CHECK OPERATION AM HAY KHONG 
    
    JE SNUMBERL1     ; NEU KHONG AM THI BO QUA VIEC 
	
	MOV AH, '-'
    
    CALL LCD_WRITE_CHAR     

SNUMBERL1:
	
	MOV AX, RESULT 
	
	ADD AX, 0030H 
	
	MOV AH, AL 
	
	CALL LCD_WRITE_CHAR 
	
	CALL PRINT 
	MOV CDOT, 0  
	
	JMP FUNCTION_CHO
    
        
NF1:             
    MOV DL,2
	MOV DH,15
	CALL LCD_SET_CUR   
	
	
	CMP RESULT, 0
	
	JNE TNUMBER0 
	
	MOV SIGN, 0; 

TNUMBER0: 	
    CMP SIGN, 0  ; CHECK OPERATION AM HAY KHONG 
    
    JE EXIT1  
	
	MOV AH, '-'
    
    CALL LCD_WRITE_CHAR     

EXIT1: 	
	MOV AX, RESULT 
	
	ADD AX, 0030H 
	
	MOV AH, AL 
	
	CALL LCD_WRITE_CHAR
	
	JMP FUNCTION_CHO
	
    
;*******************************	 
NUMBERL5: 
    MOV N_COUNT, 5
    
    CMP CDOT, 1  ;CO XAC NHAN CO NUMBER FLOAT
    JNE NF5     
    
    CMP SIGN, 1  ;NEU CO OPERATOR AM 
    JNE NF5
    
    MOV DL,2
	MOV DH,7
	CALL LCD_SET_CUR 
	
	CMP SIGN, 0  ; CHECK OPERATION AM HAY KHONG 
    
    JE SNUMBERL5     ; NEU KHONG AM THI BO QUA VIEC 
	
	MOV AH, '-'
    
    CALL LCD_WRITE_CHAR     

SNUMBERL5:
	
	CALL PRINT 
	MOV CDOT, 0
	JMP FUNCTION_CHO

NF5:     
    
    MOV DL,2
	MOV DH,11
	CALL LCD_SET_CUR  
	
	CMP SIGN, 0
	JE SNF5
	MOV AH, '-'
	CALL LCD_WRITE_CHAR		
SNF5:
	
	CALL PRINT 
		
	JMP FUNCTION_CHO 
;*******************************		  
    
NUMBERL4:  
    MOV N_COUNT, 4

    CMP CDOT, 1  
    JNE NF4    
    
    
    MOV DL,2
	MOV DH,8
	CALL LCD_SET_CUR  
	
	CMP SIGN, 0  ; CHECK OPERATION AM HAY KHONG 
    
    JE SNUMBERL4    ; NEU KHONG AM THI BO QUA VIEC 
	
	MOV AH, '-'
    
    CALL LCD_WRITE_CHAR     

SNUMBERL4:
	
	CALL PRINT 
	MOV CDOT, 0
	JMP FUNCTION_CHO

NF4:   
    MOV DL,2
	MOV DH,12
	CALL LCD_SET_CUR 
	
	CMP SIGN, 0
	JE SNF4
	MOV AH, '-'
	CALL LCD_WRITE_CHAR		
SNF4:
	
	CALL PRINT 
	
	JMP FUNCTION_CHO
;*******************************	
	       
NUMBERL3: 
    MOV N_COUNT, 3

    CMP CDOT, 1  
    JNE NF3    
    
    
    MOV DL,2
	MOV DH,9
	CALL LCD_SET_CUR
	
	CMP SIGN, 0  ; CHECK OPERATION AM HAY KHONG 
    
    JE SNUMBERL3     ; NEU KHONG AM THI BO QUA VIEC 
	
	MOV AH, '-'
    
    CALL LCD_WRITE_CHAR     

SNUMBERL3: 
	
	CALL PRINT 
	MOV CDOT, 0
	JMP FUNCTION_CHO

NF3:  
    
    MOV DL,2
	MOV DH,13
	CALL LCD_SET_CUR 
	MOV N_COUNT, 3 
	
	CMP SIGN, 0
	JE SNF3
	MOV AH, '-'
	CALL LCD_WRITE_CHAR		
SNF3:
	CALL PRINT 
	
	JMP FUNCTION_CHO
;********************************	
	
NUMBERL2: 
  
    MOV N_COUNT, 2

    CMP CDOT, 1  
    JNE NF2    
    
    
    MOV DL,2
	MOV DH,10
	CALL LCD_SET_CUR 
	
	                                             
    CMP SIGN, 0  ; CHECK OPERATION AM HAY KHONG 
    
    JE SNUMBERL2     ; NEU KHONG AM THI BO QUA VIEC 
	
	MOV AH, '-'
    
    CALL LCD_WRITE_CHAR     

SNUMBERL2:
	
	CALL PRINT 
	MOV CDOT, 0
	JMP FUNCTION_CHO

NF2: 

    MOV DL,2
	MOV DH,14
	CALL LCD_SET_CUR 
	
	
	MOV N_COUNT, 2 
	
	CMP SIGN, 0
	JE SNF2
	MOV AH, '-'
	CALL LCD_WRITE_CHAR		
SNF2:

	CALL PRINT 
	
	JMP FUNCTION_CHO
;********************************
FUNCTION_CHO:
         
    ;  QUET HANG THU 1
    MOV AL, 11111110B
    OUT PC, AL 
    MOV CX, 250
    CALL DELAY     
    IN AL, PC  
        
                      
    CMP AL, 01111110b ; NEU AN NUT /
    JNE N_CHIA
    
    CALL LCD_CLEAR
    LEA SI, SANS
    CALL LCD_WRITE_STR
    MOV AH, '/' 
    CALL LCD_WRITE_CHAR 
    
    MOV OPERATOR,'/' 
    MOV NUM2, 0 
    MOV AX, ANS
    MOV NUM1, AX
    
    
    JMP KEYPAD     
    
    
     
    ; QUET HANG THU 2
N_CHIA: 

    MOV AL, 11111101b
    OUT PC, AL     
    MOV CX, 250
    CALL DELAY    
    IN AL, PC   
    
      
    
    CMP AL, 01111101b  ; NEU AN NUT X
    JNE N_NHAN
    
    
    CALL LCD_CLEAR
    LEA SI, SANS
    CALL LCD_WRITE_STR
    MOV AH, '*' 
    CALL LCD_WRITE_CHAR
    
    MOV OPERATOR,'*' 
    MOV NUM2, 0 
    MOV AX, ANS
    MOV NUM1, AX
    
    JMP KEYPAD   
    
    
    ; QUET HANG THU 3
N_NHAN:      
    MOV AL, 11111011b
    OUT PC, AL  
    
    MOV CX, 250 
    CALL DELAY  
    
    IN AL, PC   
    
    CMP AL, 01111011b  ; KHI NHAN OPERATOR TRU
    JNE N_TRU
    
    
    CALL LCD_CLEAR
    LEA SI, SANS
    CALL LCD_WRITE_STR
    
    MOV AH, '-'  
    CALL LCD_WRITE_CHAR 
    
   
    MOV OPERATOR,'-'
    
    CMP SIGN, 1    ; NEU LAY NUMBER AM TRU 
    
    JNE NTRUAM
    
    MOV OPERATOR, '+'  
    
NTRUAM:       
    MOV NUM2, 0 
    MOV AX, ANS
    MOV NUM1, AX
    
    JMP KEYPAD      
    
    
    ; QUET HANG THU 4 
N_TRU:     
    MOV AL, 11110111b
    OUT PC, AL    
    MOV CX, 250
    CALL DELAY    
    IN AL, PC    
    
    CMP AL, 11100111b
    JE C
      
    CMP AL, 01110111b  ; KHI NHAN OPERATOR CONG 
    
    JNE CHO_TIEP 
    
    CALL LCD_CLEAR
    LEA SI, SANS
    CALL LCD_WRITE_STR
    MOV AH, '+' 
    CALL LCD_WRITE_CHAR 
    
    MOV OPERATOR,'+'
    
    CMP SIGN, 1   ; NEU LA PHEP CONG AM 
    
    JNE NCONGAM
    
    MOV OPERATOR, '-'  
    
NCONGAM:
    
    MOV NUM2, 0 
    MOV AX, ANS
    MOV NUM1, AX
    
    JMP KEYPAD 
    
CHO_TIEP: 
    JMP FUNCTION_CHO
         

;********************************	    
    
HLT  
 
 
ENDP MAIN
;*************************************
;                                    ;
;                                    ;
;     FUNCTION THU TUC IN RA MAN HINH     ;
;                                    ;
;                                    ;
;*************************************
PROC PRINT  
    
    CMP N_COUNT, 5
    
    JE EXIT5 
    
    CMP N_COUNT, 4
    
    JE EXIT4
    
    CMP N_COUNT, 3
    
    JE EXIT3
    
    CMP N_COUNT, 2
    
    JE EXIT2
           
           
    CMP N_COUNT, 1
    JE CHECKF 

    

EXIT5: 
    
    
    XOR DX, DX
           
    MOV AX, RESULT 
    
    MOV BX, 10000 
    
    DIV BX
    
    ADD AX, 0030H 
    
    MOV RESULT, DX
    
    MOV AH, AL 
    
    CALL LCD_WRITE_CHAR
    



EXIT4:     
    XOR DX, DX
           
    MOV AX, RESULT 
    
    MOV BX, 1000 
    
    DIV BX
    
    ADD AX, 0030H 
    
    MOV RESULT, DX
    
    MOV AH, AL 
    
    CALL LCD_WRITE_CHAR
      

EXIT3:            
    XOR DX, DX
           
    MOV AX, RESULT 
    
    MOV BX, 100 
    
    DIV BX
    
    ADD AX, 0030H 
    
    MOV RESULT, DX
    
    MOV AH, AL 
    
    CALL LCD_WRITE_CHAR 
    
    
EXIT2: 
    
    XOR DX, DX
           
    MOV AX, RESULT 
    
    MOV BX, 10 
    
    DIV BX
    
    ADD AX, 0030H 
    
    MOV RESULT, DX
    
    MOV AH, AL 
    
    CALL LCD_WRITE_CHAR    
    
       
    MOV AX, RESULT
    
    ADD AX, 0030H 
    
    MOV AH, AL 
    
    CALL LCD_WRITE_CHAR  
    


CHECKF:     
    CMP CDOT, 1
    
    JNE NFOAT
    
    MOV AH, '.'
    
    CALL LCD_WRITE_CHAR 
    
    MOV N, 3
    
    SAUCFUNCTION:
        MOV AX, CRESULT
        
        MOV BX, 10
        MUL BX
        
        XOR DX, DX 
        MOV BX, NUM2 
        
        DIV BX
        
        MOV CRESULT, DX 
         
        
        ADD AX, 0030H 
        
        MOV AH, AL 
        
        CALL LCD_WRITE_CHAR
    
        MOV CX, N
        
        SUB CX, 1
        
        MOV N, CX
        
        CMP N, 0 
        
        JNE SAUCFUNCTION
      
NFOAT:                    
        
    RET  
    
ENDP PRINT
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                                    ;
;		LCD function library.        ;
;                                    ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  

PROC DELAY
	JCXZ @DELAY_END
	@DEL_LOOP:
	LOOP @DEL_LOOP	
	@DELAY_END:
	RET
ENDP DELAY



; LCD INITIALIZATION FUNCTION 
PROC LCD_INIT

 
 
;DUA CHAN  RS=En=RW=0 DE KHOI TAO COMMAND 
	MOV AL,0
	CALL OUT_B  
	
; TAO TRE 20MS 
	MOV CX,1000
	CALL DELAY   
	
;RESSET LAI CAU HINH
	MOV AH,30H
	CALL LCD_CMD
	MOV CX,250
	CALL DELAY
	
	MOV AH,30H
	CALL LCD_CMD
	MOV CX,50
	CALL DELAY
	
	MOV AH,30H
	CALL LCD_CMD
	MOV CX,500
	CALL DELAY
	
;SET CAU HINH CHO LCD  

	MOV AH,38H  ; LCD 2 HANG VA 5X7 CFUNCTION
	CALL LCD_CMD
	
	MOV AH,0CH ; CMD DISPLAY ON VA CURNUMBERR OFF
	CALL LCD_CMD
	
	MOV AH,01H ; CLEAR DISPLAY SCREEN
	CALL LCD_CMD
	
	MOV AH,06H ; CHE DO CON TRO TANG DAN DI CHUYEN SANG PHAI
	CALL LCD_CMD
	
	RET	
ENDP LCD_INIT




;FUNCTION GUI LENH COMMAND TOI LCD 
PROC LCD_CMD

; OPERATOR VAO AH LA CAC COMMAND CODE    

	PUSH DX
	PUSH AX

; DUA RS XUONG 0 DE LAM VIEC O CHE DO CMD 

	MOV AL,PORTB_VAL
	AND AL,0FDH		;En-RS-RW
	CALL OUT_B  
	
;set out data pins
	MOV AL,AH
	CALL OUT_A 
	
;make En=1
	MOV AL,PORTB_VAL
	OR	AL,100B		;En-RS-RW
	CALL OUT_B  
	
;delay 1ms
	MOV CX,50
	CALL DELAY 
	
;make En=0
	MOV AL,PORTB_VAL
	AND AL,0FBH		;En-RS-RW
	CALL OUT_B 
	
;delay 1ms
	MOV CX,50
	CALL DELAY 
	
;restore registers
	POP AX
	POP DX	
	RET
ENDP LCD_CMD




PROC LCD_CLEAR
	MOV AH,1
	CALL LCD_CMD
	RET	
ENDP LCD_CLEAR




PROC LCD_WRITE_CHAR
;input: AH
;output: none

;save registers
	PUSH AX   
	
; DUA RX  = 1  LAM VIEC VOI THANH GHI DATA 
	MOV AL,PORTB_VAL
	OR	AL,10B		;EN-RS-RW
	CALL OUT_B       
	
;DUA DU LIEU KI TU RA PORT A
	MOV AL,AH
	CALL OUT_A
; DUA CHAN EN LEN MUC CAO 

	MOV AL,PORTB_VAL
	OR	AL,100B		;EN-RS-RW
	CALL OUT_B 
	
; TAO XUNG 1MS O CHAN EN 
	MOV CX,50
	CALL DELAY
	
; DUA CHAN EN XUONG MUC THAP 

	MOV AL,PORTB_VAL
	AND	AL,0FBH		;EN-RS-RW
	CALL OUT_B 
	
;return
	POP AX
	RET	
ENDP LCD_WRITE_CHAR





; FUNCTION IN RA MOT CHUOI 

PROC LCD_WRITE_STR
;input: DIA CHI CUA MANG KI TU KET THUC BANG '$'
;output: none

	PUSH SI
	PUSH AX
	
;read and write character
	@LCD_PRINTSTR_LT:
		LODSB ; LENH QUET CHUOI   
		
		
		CMP AL,'$'  ; TIM KI HIEU KET THUC CHUOI 
		
		JE @LCD_PRINTSTR_EXIT ; NEU THAY $ THI DUNG VIEC DOC CHUOI 
		
		MOV AH,AL
		CALL LCD_WRITE_CHAR	
	JMP @LCD_PRINTSTR_LT
	
;return
	@LCD_PRINTSTR_EXIT:
	POP AX
	POP SI
	RET	
ENDP LCD_WRITE_STR




;sets the cursor
PROC LCD_SET_CUR 
    
    
;input: DL=HANG, DH=COT
;		DL = 1, LA HANG TREN
;		DL = 2,LA HANG DUOI 
;		DH = 1-8, LA NUMBER COT CHAY TU 1 -> 8 

	PUSH AX
;LCD uses 0 based column index
	DEC DH
;select case	
	CMP DL,1
	JE	@ROW1
	CMP DL,2
	JE	@ROW2
	JMP @LCD_SET_CUR_END
	
;if DL==1 then
	@ROW1:
		MOV AH,80H
	JMP @LCD_SET_CUR_ENDCASE
	
;if DL==2 then
	@ROW2:
		MOV AH,0C0H
	JMP @LCD_SET_CUR_ENDCASE
		
;execute the command
	@LCD_SET_CUR_ENDCASE:	
	ADD AH,DH
	CALL LCD_CMD
	
;exit from procedure
	@LCD_SET_CUR_END:
	POP AX
	RET
ENDP LCD_SET_CUR






PROC LCD_SHOW_CUR   ; LENH SHOW RA CON TRO INPUT NHAY 
	PUSH AX
	MOV AH,0FH
	CALL LCD_CMD
	POP AX
	RET
ENDP LCD_SHOW_CUR




PROC LCD_HIDE_CUR
;input: none
;output: none
	PUSH AX
	MOV AH,0CH
	CALL LCD_CMD
	POP AX
	RET
ENDP LCD_HIDE_CUR



; FUNCTION GUI DU LIEU XUONG CAC PORT
PROC OUT_A
	PUSH DX
	MOV DX,PA
	OUT DX,AL
	MOV PORTA_VAL,AL
	POP DX
	RET	
ENDP OUT_A


PROC OUT_B

	PUSH DX
	MOV DX,PB
	OUT DX,AL
	MOV PORTB_VAL,AL
	POP DX
	RET
ENDP OUT_B

PROC OUT_C
	PUSH DX
	MOV DX,PC
	OUT DX,AL
	MOV PORTC_VAL,AL
	POP DX
	RET
ENDP OUT_C