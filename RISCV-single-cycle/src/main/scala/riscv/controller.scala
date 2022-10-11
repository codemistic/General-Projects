package riscv
import chisel3._
import chisel3.util._
class counterIO extends Bundle{
    val in = Input ( UInt (7. W ) )
    val memwrite = Output ( Bool () )
    val branch = Output(Bool())
    val memread = Output(Bool())
    val regwrite =Output(UInt(1.W))
    val memtoreg=Output(Bool())
    val aluop=Output(UInt(3.W))
    val opA=Output(UInt(4.W))
    val opB=Output(UInt(2.W))
    val extendsel=Output(UInt(4.W))
    val nextpcsel=Output(UInt(4.W))
}
class controller extends Module {
    val io = IO (new counterIO())
    io .memwrite :=0.B
    io.branch:=0.B
    io.memread:=0.B 
    io.regwrite :=0.U
    io.memtoreg:=0.B
    io.aluop:=0.U
    io.opA :=0.U
    io.opB :=0.U
    io.extendsel :=0.U
    io.nextpcsel :=0.U
    switch ( io . in ) {
        is ("b0010011". U ) {     //I type addi
             io .memwrite :=0.B
             io.branch:=0.B
             io.memread:=0.B 
             io.regwrite :=1.U
             io.memtoreg:=0.B
             io.aluop:=1.U
             io.opA :=0.U
             io.opB :=1.U
             io.extendsel :=0.U
             io.nextpcsel :=0.U
             }
        
        is ("b0110011". U ) {       //R type add
            io .memwrite :=0.B
             io.branch:=0.B
             io.memread:=0.B 
             io.regwrite :=1.U
             io.memtoreg:=0.B
             io.aluop:=0.U
             io.opA :=0.U
             io.opB :=0.U
             io.extendsel :=0.U
             io.nextpcsel :=0.U
             }
        
        is ("b0100011". U ) {       //S type sw
            io.memwrite :=1.B  
            io.branch:=0.B
            io.memread:=0.B 
            io.regwrite :=0.U
            io.memtoreg:=0.B
            io.aluop:=5.U
            io.opA :=0.U
            io.opB :=1.U
            io.extendsel :=2.U
            io.nextpcsel :=0.U}

        is ("b0000011". U ) {       //I type lw
            io .memwrite :=0.B
            io.branch:=0.B
            io.memread:=1.B 
            io.regwrite :=1.U
            io.memtoreg:=1.B
            io.aluop:=3.U
            io.opA :=0.U
            io.opB :=1.U
            io.extendsel :=0.U
            io.nextpcsel :=0.U}

        is ("b1100011". U ) {       //SB type beq
            io .memwrite :=0.B
             io.branch:=1.B
             io.memread:=0.B 
             io.regwrite :=0.U
             io.memtoreg:=0.B
             io.aluop:=2.U
             io.opA :=0.U
             io.opB :=0.U
             io.extendsel :=0.U
             io.nextpcsel :=1.U}

        is ("b1101111". U ) {       //UJ type jal
            io .memwrite :=0.B
             io.branch:=0.B
             io.memread:=0.B 
             io.regwrite :=1.U
             io.memtoreg:=0.B
             io.aluop:=3.U
             io.opA :=2.U
             io.opB :=0.U
             io.extendsel :=0.U
             io.nextpcsel :=2.U}

        is ("b1100111". U ) {       //i type jalr
            io .memwrite :=0.B
             io.branch:=0.B
             io.memread:=0.B 
             io.regwrite :=1.U
             io.memtoreg:=0.B
             io.aluop:=3.U
             io.opA :=2.U
             io.opB :=0.U
             io.extendsel :=0.U
             io.nextpcsel :=3.U}

        is ("b0110111". U ) {       //U type lui
            io .memwrite :=0.B
             io.branch:=0.B
             io.memread:=0.B 
             io.regwrite :=1.U
             io.memtoreg:=0.B
             io.aluop:=6.U
             io.opA :=3.U
             io.opB :=1.U
             io.extendsel :=2.U
             io.nextpcsel :=0.U}
             
    }
}
