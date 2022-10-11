package riscv
import chisel3 . _
import chisel3 . util . _
class immediateIO extends Bundle {
    val instr = Input ( UInt (32. W ) )
    val iimmd_se = Output ( UInt (32. W ) )
    val simmd_se = Output ( UInt (32. W ) )
    val sbimmd_se = Output ( UInt (32. W ) )
    val uimmd_se = Output ( UInt (32. W ) )
    val ujimmd_se = Output ( UInt (32. W ) )
    val pc=Input(UInt(32.W))
}
class immediate extends Module {
    val io = IO (new immediateIO )
    val opcodes =io.instr(6,0)
    io.iimmd_se:=0.U
    io.simmd_se:=0.U
    io.sbimmd_se:=0.U
    io.ujimmd_se:=0.U
    io.uimmd_se:=0.U

    io.iimmd_se:=Cat(Fill(20,io.instr(31)),io.instr(31,20))//i type
        
    io.simmd_se:=Cat(Fill(20,io.instr(31)),io.instr(31,25),io.instr(11,7))//s type
        
    io.sbimmd_se:=Cat(Fill(19,io.instr(31)),io.instr(31),io.instr(7),io.instr(30,25),io.instr(11,8)) + io.pc//sb type

    io.uimmd_se:=Cat(Fill(12,io.instr(31)),io.instr(31,12))//u type

    io.ujimmd_se:=Cat(Fill(12,io.instr(31)),io.instr(31),io.instr(19,12),io.instr(20),io.instr(31,21)) +io.pc//uj type
}
