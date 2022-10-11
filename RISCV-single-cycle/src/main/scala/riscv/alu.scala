package riscv
import chisel3._
import chisel3.util._

class ALUIO extends Bundle {
    val in_A = Input ( UInt (32 .W ) )
    val in_B = Input ( UInt ( 32 . W ) )
    val alu_Op = Input ( UInt ( 5 . W ) )
    val out = Output ( UInt ( 32 . W ) )
    //val branch=Output(UInt(1.W))
}
class ALU extends Module  {
    val io = IO (new ALUIO )
    io.out:=0.U
    //io.branch:=0.U
    switch (io . alu_Op){
        is("b00000".U){     //addi  add
            io.out:=io.in_A + io.in_B}
        is( "b01000".U){    //sub
            io.out:=io.in_A - io.in_B}
        is( "b00100".U){   // xori xor
            io.out :=io.in_A ^ io.in_B}
        is("b00110".U ){   //or ori
            io.out:=io.in_A|io.in_B}
        is("b00111".U ){    //and andi
            io.out:=io.in_A & io.in_B}
        is("b11111".U ){   //jal jalr
            io.out:=io.in_A}
        is("b00001".U ){     //sll slli
            io.out:=io.in_A<<io.in_B(4,0)}
        is("b00101".U){
            io.out:=io.in_A>>io.in_B(4,0)}   //srl srli sra srai
        is("b00010".U){
            when(io.in_A < io.in_B){      //slt slti  sltu
                io.out:=1.U
            }.otherwise{
                io.out:=0.U
            }
        }
         
        
        
    }
}
    
// is("b10000".U){                 
        //     when(io.in_A===io.in_B){    //beq
        //         io.branch:=1.U
        //     }.otherwise{
        //         io.branch:=0.U
        //     }
        // }
        // is("b10011".U){
        //     when(io.in_A=/=io.in_B){    //bne
        //         io.branch:=1.U
        //     }.otherwise{
        //         io.branch:=0.U
        //     }
        // }
        // is("b10110".U){    //bltu 
        //     when(io.in_A < io.in_B){
        //         io.branch:=1.U
        //     }.otherwise{
        //         io.branch:=0.U
        //     }
        // }
        // is("b10101".U){
        //     when(io.in_A >= io.in_B){   //bge
        //         io.branch:=1.U
        //     }.otherwise{
        //         io.branch:=0.U
        //     }
        // }
        // is("b10111".U){
        //     when(io.in_A>=io.in_B){     //bgeu
        //         io.branch:=1.U
        //     }.otherwise{
        //         io.branch:=0.U
        //     }
        // }

//     io.out:=0.U
//     switch(io.alu_Op){
//         is("b00000".U){ io.out:=io.in_A+io.in_B}//add addi
//         is("b00001".U){io.out:=io.in_A<<io.in_B(4,0) } //sll
//         is("b00010".U){  
//             when(io.in_A<io.in_B) 
//             {io.out:=1.U}.otherwise{
//                 io.out:=0.U}} //slt
//         is("b00011".U ){
//             when(io.in_A<io.in_B){io.out:=1.U}.otherwise{io.out:=0.U}
//         }           // SLTU/SLTUI/BLTU
//         is("b10110".U){
//             when(io.in_A<io.in_B){io.out:=1.U}.otherwise{io.out:=0.U}
//         }     
//         is("b00100".U){io.out:=io.in_A ^ io.in_B} //xor
//         is("b00101".U){io.out:=(io.in_A>>io.in_B(4,0))} //srl
//         is("b00110".U){io.out:=io.in_A| io.in_B} //or
//         is("b00111".U){io.out:=io.in_A & io.in_B} //and
//         is("b01000".U){io.out:=io.in_A - io.in_B} //sub
//         is("b01101".U){io.out:=(io.in_A>>io.in_B(4,0))} //sra
//         is("b11111".U){io.out:= io.in_A} //jal jarlr


//     }


// }