package riscv
import chisel3._
import chisel3 . util . _
class Top extends Module{
    val io = IO(new Bundle{
        val out = Output(UInt(32.W))
    })
    val pc_module = Module(new pc)
    val aluctrl_module = Module(new alucontrol)
    val alu_module = Module(new ALU)
    val control_module = Module(new controller)
    val imem_module = Module(new imem)
    val immediate_module = Module(new immediate)
    val jalr_module = Module(new JALR)
    val register_module = Module(new register)
    val smem_module = Module(new memory)
    val branch_module = Module(new branchControl)

    //pc ki vaue instruction memory main
    pc_module.io.addr:=pc_module.io.pc_out4
    imem_module.io.address:=pc_module.io.pc_out(11,2) 
      
    val instruction = imem_module.io.readdata

    //opcode instruction main se control main
    control_module.io.in :=instruction(6,0)  
 

    // register ke input die
    register_module.io.regwrite:=control_module.io.regwrite 
    register_module.io.rs1:=instruction(19,15)  
    register_module.io.rs2:=instruction(24,20)  
    register_module.io.writereg:=instruction(11,7)  
    register_module.io.regwrite:=control_module.io.regwrite 

    //immediate main pc or instr ki value aigi
    immediate_module.io.instr:=imem_module.io.readdata  
    immediate_module.io.pc:=pc_module.io.pc_out     

    //aluop ki value  control se aluctrl main gai      
    //instruction memory se instruction f7 or f3 main gai
     //alucontrol ka output alu ke alu_op main jaiga
    aluctrl_module.io.alu := control_module.io.aluop    
    aluctrl_module.io.f7 := instruction(30)     
    aluctrl_module.io.f3:= instruction(14,12)  
    alu_module.io.alu_Op := aluctrl_module.io.alucontrolout 
    branch_module.io.aluop:=aluctrl_module.io.alucontrolout 


    //immediate ka mux
    //alu A KA MUX
    //alu_module.io.in_A := Mux1H (control_module.io.opA , Seq (register_module.io.rd1.asUInt,pc_module.io.pc_out4 ,pc_module.io.pc_out,register_module.io.rd1.asUInt ) )
    
    // Controlling Operand A for ALU
    when(control_module.io.opA === "b10".U) {
        alu_module.io.in_A:= pc_module.io.pc_out4
        branch_module.io.arg_x:= pc_module.io.pc_out4.asSInt
    }.elsewhen(control_module.io.opA === "b01".U){
        alu_module.io.in_A:=pc_module.io.pc_out
        branch_module.io.arg_x:=pc_module.io.pc_out.asSInt
    } .otherwise {
        alu_module.io.in_A := register_module.io.rd1.asUInt
        branch_module.io.arg_x:=register_module.io.rd1
    }

    //alu B ka mux
    //alu_module.io.in_B := Mux1H (control_module.io.opB , Seq (register_module.io.rd2.asUInt,Mux1H (control_module.io.extendsel , Seq ( immediate_module.io.iimmd_se,immediate_module.io.simmd_se ,immediate_module.io.uimmd_se  ) )))
    
    // Controlling Operand B for ALU based on the Control signal Operand_b_sel and Extend_sel
    when(control_module.io.opB === "b1".U) {
        when(control_module.io.extendsel === "b00".U) {
            // I-Type
            alu_module.io.in_B := immediate_module.io.iimmd_se
            branch_module.io.arg_y:=immediate_module.io.iimmd_se.asSInt
        }.elsewhen(control_module.io.extendsel === "b01".U) {
            // S-Type
            alu_module.io.in_B := immediate_module.io.simmd_se
            branch_module.io.arg_y:=immediate_module.io.simmd_se.asSInt
        }.elsewhen(control_module.io.extendsel === "b10".U) {
            // U-Type
            alu_module.io.in_B := immediate_module.io.uimmd_se
            branch_module.io.arg_y:=immediate_module.io.simmd_se.asSInt
        }.otherwise{
            alu_module.io.in_B:= 0.U(32.W)
            branch_module.io.arg_y:=0.S(32.W)
        }
    }.otherwise {
        alu_module.io.in_B := register_module.io.rd2.asUInt
        branch_module.io.arg_y:=register_module.io.rd2
    }

    //branch ki value initialize kia
    //branch_module.io.arg_x:= 0.S
   // branch_module.io.arg_y:= 0.S
    //branch_module.io.aluop:=control_module.io.aluop
    branch_module.io.branch:=control_module.io.branch

    //val branch=control_module.io.branch===1.U && branch_module.io.br_taken===1.U
    //io . out := Mux1H (branch , Seq ( pc_module.io.pc_out4,immediate_module.io.sbimmd_se  ) )
    //pc ka input dia mux ke zarie
    //pc_module.io.addr := Mux1H (control_module.io.nextpcsel, Seq ( pc_module.io.pc_out4,Mux1H ((control_module.io.branch===1.U && branch_module.io.br_taken===1.U) , Seq ( pc_module.io.pc_out4,immediate_module.io.sbimmd_se  ) ) ,immediate_module.io.ujimmd_se,jalr_module.io.out) )
    when(control_module.io.nextpcsel === "b01".U) {
        when(control_module.io.branch === 1.U && branch_module.io.br_taken === 1.U) {
            pc_module.io.addr := immediate_module.io.sbimmd_se
        } .otherwise {
            pc_module.io.addr := pc_module.io.pc_out4
        }
    } .elsewhen(control_module.io.nextpcsel === "b10".U) {
        pc_module.io.addr := immediate_module.io.ujimmd_se
    } .elsewhen(control_module.io.nextpcsel === "b11".U) {
        pc_module.io.addr := jalr_module.io.out
    } .otherwise {
        pc_module.io.addr := pc_module.io.pc_out4
    }

    
    //jalr banaya hai
    jalr_module.io.addr:=immediate_module.io.iimmd_se
    jalr_module.io.pc:=register_module.io.rd1.asUInt


    //storage memory main input dia
    smem_module.io.addr:=alu_module.io.out(9,2)
    smem_module.io.data:=register_module.io.rd2.asUInt
    smem_module.io.w_enable:=control_module.io.memwrite
    smem_module.io.r_enable:=control_module.io.memread

    smem_module.io.data:=register_module.io.rs2


    // when(control_module.io.memtoreg === 0.B){
    //     register_module.io.writedata := alu_module.io.out.asSInt 
    // }.otherwise{
    //     register_module.io.writedata:=smem_module.io.output.asSInt
    // } 
    
    //register ke adndar data save hoga storage or alu ka mux ke zarie
    register_module.io.writedata := Mux(control_module.io.memtoreg,smem_module.io.output.asSInt,alu_module.io.out.asSInt  )  
    
    io.out:=register_module.io.rs1
}