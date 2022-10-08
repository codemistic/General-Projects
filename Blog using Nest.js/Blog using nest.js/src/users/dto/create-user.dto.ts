import { IsEmail, IsNotEmpty, IsString, MinLength } from "class-validator"

export class CreateUserDto {
    @IsString()
    @IsNotEmpty({message: 'Name is required'})
    @MinLength(5, {
        message: "Name is too short"
    })
    name: string
    @IsString()
    @IsEmail()
    @IsNotEmpty({message: 'Email is required'})
    @MinLength(5, {
        message: "Email is too short"
    })
    email: string
    @IsString()
    @IsNotEmpty({message: 'Password is required'})
    @MinLength(5, {
        message: "Password is too short"
    })
    password: string
}
