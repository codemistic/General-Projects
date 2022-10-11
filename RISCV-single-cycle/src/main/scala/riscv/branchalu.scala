package riscv
import chisel3 . _
import chisel3 . util . _
class LM_IO_Interface_BranchControl extends Bundle {
    val aluop = Input ( UInt (5. W ) )
    val branch = Input ( Bool () )
    val arg_x = Input ( SInt (32. W ) )
    val arg_y = Input ( SInt (32. W ) )
    val br_taken = Output ( Bool() )
}
class branchControl extends Module {
    val io = IO (new LM_IO_Interface_BranchControl )
// Start Coding here
    val out=Wire(Bool())
    out:=0.B
    switch(io.aluop){
        is("b10000".U){
            out:=io.arg_x === io.arg_y}//equal
        is("b10001".U){
            out:=io.arg_x =/= io.arg_y}//not equal
        is("b10100".U){
            out:=io.arg_x > io.arg_y}//lesser equal
        is("b10101".U){
            out:=io.arg_x < io.arg_y}//greaterequal
        is("b10110".U){
            out:=io.arg_x <= io.arg_y}//lesserthenunsign
        is("b10111".U){
            out:=io.arg_x >= io.arg_y}////branchgraterequalunsign
        // is("b00011".U ){
        //     out:=io.arg_x<io.arg_y}//// SLTU/SLTUI/BLTU
        // is("b00010".U){
        //     out:=io.arg_x<io.arg_y}//slt slti
        // }
    }
    io.br_taken := out
}


