package riscv
import chisel3._
import chisel3.util._
import chisel3.util.experimental.loadMemoryFromFile
class imem extends Module{
    val io = IO(new Bundle{
        val address = Input(UInt(32.W))
        val readdata =Output(UInt(32.W))
    })
    val mem=Mem(32,UInt(32.W))
    io.readdata :=mem(io.address)
    loadMemoryFromFile(mem,"C:/Users/F I ENTERPRISES/Music/file.txt")
}