import { IsNotEmpty, IsString, MinLength, IsArray } from 'class-validator';
import { Type } from 'class-transformer';
import { LinkPayload } from 'src/utils/payload';

export class CreatePostDto {
  @MinLength(5, {
    message: 'Title is too short',
  })
  @IsNotEmpty({ message: 'Title is required' })
  @IsString()
  title: string;

  @MinLength(10, {
    message: 'Body is too short',
  })
  @IsNotEmpty({ message: 'Body is required' })
  @IsString()
  body: string;

  @IsString()
  categoryId: string;

  @IsString()
  subCategoryId: string;

  @IsArray()
  @Type(() => LinkPayload)
  name: LinkPayload[];
}
