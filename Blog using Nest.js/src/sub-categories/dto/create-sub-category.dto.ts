import { IsNotEmpty, IsString, MinLength } from 'class-validator';

export class CreateSubCategoryDto {
  @MinLength(3, {
    message: 'Name is too short.',
  })
  @IsNotEmpty({ message: 'Name is required' })
  @IsString()
  name: string;
  @IsNotEmpty({ message: 'Category ID is required' })
  @IsString()
  categoryId: string;
}
