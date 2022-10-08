import { IsNotEmpty, IsString, MinLength } from 'class-validator';

export class CreateCategoryDto {
  @MinLength(3, {
    message: 'Name is too short',
  })
  @IsNotEmpty({ message: 'Name is required' })
  @IsString()
  name: string;
}
